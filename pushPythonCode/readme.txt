免输入密钥文件 : Enter PEM pass phrase
openssl rsa -in key.pem-out key.pem.unsecure

使用  key.pem.unsecure 就可以不输入密码了

apns = APNS_SERVICE(server_ip="17.172.233.65", server_port=2195, certfile="key/cert.pem", keyfile="key/key.pem.unsecure")
这里 certfile 制定自己的cert.pem,  keyfile指定自己的key.pem.unsecure(去除输入密码的)

