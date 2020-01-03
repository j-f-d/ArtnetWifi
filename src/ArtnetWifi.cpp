/*The MIT License (MIT)

Copyright (c) 2014 Nathanaël Lécaudé
https://github.com/natcl/Artnet, http://forum.pjrc.com/threads/24688-Artnet-to-OctoWS2811

Copyright (c) 2016,2019 Stephan Ruloff
https://github.com/rstephan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <ArtnetWifi.h>

const char ArtnetWifi::artnetId[] = ART_NET_ID;

ArtnetWifi::ArtnetWifi() {}

void ArtnetWifi::begin(String hostname)
{
  Udp.begin(DefaultPortArt);
  host = hostname;
  sequence = 1;
  physical = 0;
}

uint16_t ArtnetWifi::read(void)
{
  packetSize = Udp.parsePacket();

  if (packetSize <= MAX_BUFFER_ARTNET && packetSize > 0)
  {
      Udp.read(artnetPacket.raw, packetSize);

      // Check that packetID is "Art-Net" else ignore
      if (memcmp(artnetPacket.raw, artnetId, sizeof(artnetId)) != 0) {
        return 0;
      }

      opcode = artnetPacket.raw[8] | artnetPacket.raw[9] << 8;

      if (opcode == OpDmx)
      {
        sequence = artnetPacket.Dmx.Sequence;
        incomingUniverse = (artnetPacket.Dmx.Net << 8) | artnetPacket.Dmx.SubUni;
        dmxDataLength = ntohs(artnetPacket.Dmx.Length);

        if (artDmxCallback) (*artDmxCallback)(incomingUniverse, dmxDataLength,
          sequence, artnetPacket.Dmx.Data);
        if (artDmxFunc) {
          artDmxFunc(incomingUniverse, dmxDataLength, sequence, artnetPacket.Dmx.Data);
        }
        return opcode;
      }
      if (opcode == OpPoll)
      {
        return opcode;
      }
  }

  return 0;
}

uint16_t ArtnetWifi::makeDmx(void)
{
  uint16_t len;

  memcpy(artnetPacket.Dmx.ID, artnetId, sizeof(artnetId));
  artnetPacket.Dmx.OpCode = htons(OpDmx);
  artnetPacket.Dmx.ProtVerLo = ProtocolVersion;
  artnetPacket.Dmx.ProtVerHi = ProtocolVersion >> 8;
  artnetPacket.Dmx.Sequence = sequence;
  sequence++;
  if (!sequence) {
    sequence = 1;
  }
  artnetPacket.Dmx.Physical = physical;
  artnetPacket.Dmx.SubUni = outgoingUniverse;
  artnetPacket.Dmx.Net = outgoingUniverse >> 8;
  len = dmxDataLength + (dmxDataLength % 2); // make a even number
  artnetPacket.Dmx.Length = htons(len);
  
  return len;
}

int ArtnetWifi::write(void)
{
  uint16_t len;

  len = makeDmx();
  Udp.beginPacket(host.c_str(), DefaultPortArt);
  Udp.write((const uint8_t*)artnetPacket.raw, offsetof(T_ArtDmx, Data) + len);

  return Udp.endPacket();
}

int ArtnetWifi::write(IPAddress ip)
{
  uint16_t len;

  len = makeDmx();
  Udp.beginPacket(ip, DefaultPortArt);
  Udp.write((const uint8_t*)artnetPacket.raw, offsetof(T_ArtDmx, Data) + len);

  return Udp.endPacket();
}

void ArtnetWifi::setByte(uint16_t pos, uint8_t value)
{
  if (pos > 512) {
    return;
  }
  artnetPacket.Dmx.Data[offsetof(T_ArtDmx, Data) + pos] = value;
}

void ArtnetWifi::printPacketHeader(void)
{
  Serial.print("packet size = ");
  Serial.print(packetSize);
  Serial.print("\topcode = ");
  Serial.print(opcode, HEX);
  Serial.print("\tuniverse number = ");
  Serial.print(incomingUniverse);
  Serial.print("\tdata length = ");
  Serial.print(dmxDataLength);
  Serial.print("\tsequence n0. = ");
  Serial.println(sequence);
}

void ArtnetWifi::printPacketContent(void)
{
  for (uint16_t i = offsetof(T_ArtDmx, Data) ; i < dmxDataLength ; i++){
    Serial.print(artnetPacket.Dmx.Data[i], DEC);
    Serial.print("  ");
  }
  Serial.println('\n');
}
