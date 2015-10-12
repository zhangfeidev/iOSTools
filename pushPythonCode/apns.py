#!/usr/bin/env /opt/app/python-2.7/bin/python
# -*- coding: UTF-8 -*-
import sys,os
from socket import *
import ssl, time
from binascii import a2b_hex, b2a_hex
from datetime import datetime
from socket import socket, AF_INET, SOCK_STREAM
from struct import pack, unpack
from pyhs import  Manager



devicetokenString="0b948eb9f3c078d98c3daf2e3830dc7c3e8ac18868bfa0622707f450f8e6cbde"
print len(devicetokenString)

class APNS_PACKET:
	def __init__(self, command=0, DeviceTokenString="" ,  payload=""):
		self.command = command
		self.deviceToken = token_bin = a2b_hex(DeviceTokenString)
		token_length_bin = pack('>H', len(token_bin))
		self.token_length = token_length_bin
		
		self.payload_length = pack('>H', len(payload))
		self.payload = payload

		self.apns_packet = pack("=B", self.command)
		self.apns_packet += self.token_length
		self.apns_packet += self.deviceToken
		self.apns_packet += self.payload_length
		self.apns_packet += self.payload
		
	def GetApnsPacket(self):
		return self.apns_packet
	
	


class  APNS_SERVICE:
	def __init__(self, server_ip="", server_port=0, certfile="", keyfile="", pempass=""):
		self.server_ip = server_ip
		self.server_port = server_port
		self.certfile = certfile
		self.keyfile = keyfile
		self.pempass = pempass


	def sendmsg_to_client(self, deviceToken="", msg="", msgtype=1):
		sockfd = socket(AF_INET, SOCK_STREAM)
		sockfd.connect((self.server_ip, self.server_port))

		ssl_sockfd = ssl.wrap_socket(sockfd, self.keyfile, self.certfile)

		payload='{"aps":{"alert":"You get a new message! %d", "badge":5,"sound":"beep.wav"}, "acme1":"bar", "acme2":42}' % count
		anps_packet = APNS_PACKET(0, deviceToken,  payload)

		send_packet = anps_packet.GetApnsPacket()
		ssl_sockfd.write(send_packet)
	





		sockfd.close()
	
	

def main():
	try:
		apns = APNS_SERVICE(server_ip="17.172.233.65", server_port=2195, certfile="key/cert.pem", keyfile="key/key.pem.unsecure")
		apns.sendmsg_to_client(deviceToken=devicetokenString, msg="hello world", msgtype=1)
	except Exception, e:
		print e


if __name__ == '__main__':
        default_encoding = 'utf-8'
        if sys.getdefaultencoding() != default_encoding:
                reload(sys)
                sys.setdefaultencoding(default_encoding)
                reload(sys)

        main()






