
openssl.exe s_client -connect kkmspb.ru:443 -servername kkmspb.ru -tls1_2 > kkmspb_.txt

::openssl engine
pause
exit

D:\OpenSSL\1_0_0_1dll\bin>openssl s_client -connect 109.120.162.1:443 -servername kkmspb.ru -tls1
no port defined
usage: s_client args

 -host host     - use -connect instead
 -port port     - use -connect instead
 -connect host:port - who to connect to (default is localhost:4433)
 -verify arg   - turn on peer certificate verification
 -verify_return_error - return verification errors
 -cert arg     - certificate file to use, PEM format assumed
 -certform arg - certificate format (PEM or DER) PEM default
 -key arg      - Private key file to use, in cert file if
                 not specified but cert file is.
 -keyform arg  - key format (PEM or DER) PEM default
 -pass arg     - private key file pass phrase source
 -CApath arg   - PEM format directory of CA's
 -CAfile arg   - PEM format file of CA's
 -no_alt_chains - only ever use the first certificate chain found
 -reconnect    - Drop and re-make the connection with the same Session-ID
 -pause        - sleep(1) after each read(2) and write(2) system call
 -prexit       - print session information even on connection failure
 -showcerts    - show all certificates in the chain
 -debug        - extra output
 -msg          - Show protocol messages
 -nbio_test    - more ssl protocol testing
 -state        - print the 'ssl' states
 -nbio         - Run with non-blocking IO
 -crlf         - convert LF from terminal into CRLF
 -quiet        - no s_client output
 -ign_eof      - ignore input eof (default when -quiet)
 -no_ign_eof   - don't ignore input eof
 -psk_identity arg - PSK identity
 -psk arg      - PSK in hex (without 0x)
 -srpuser user     - SRP authentification for 'user'
 -srppass arg      - password for 'user'
 -srp_lateuser     - SRP username into second ClientHello message
 -srp_moregroups   - Tolerate other than the known g N values.
 -srp_strength int - minimal length in bits for N (default 1024).
 -ssl2         - just use SSLv2
 -ssl3         - just use SSLv3
 -tls1_2       - just use TLSv1.2
 -tls1_1       - just use TLSv1.1
 -tls1         - just use TLSv1
 -dtls1        - just use DTLSv1
 -fallback_scsv - send TLS_FALLBACK_SCSV
 -mtu          - set the link layer MTU
 -no_tls1_2/-no_tls1_1/-no_tls1/-no_ssl3/-no_ssl2 - turn off that protocol
 -bugs         - Switch on all SSL implementation bug workarounds
 -serverpref   - Use server's cipher preferences (only SSLv2)
 -cipher       - preferred cipher to use, use the 'openssl ciphers'
                 command to see what is available
 -starttls prot - use the STARTTLS command before starting TLS
                 for those protocols that support it, where
                 'prot' defines which one to assume.  Currently,
                 only "smtp", "pop3", "imap", "ftp" and "xmpp"
                 are supported.
 -engine id    - Initialise and use the specified engine
 -rand file;file;...
 -sess_out arg - file to write SSL session to
 -sess_in arg  - file to read SSL session from
 -servername host  - Set TLS extension servername in ClientHello
 -tlsextdebug      - hex dump of all TLS extensions received
 -status           - request certificate status from server
 -no_ticket        - disable use of RFC4507bis session tickets
 -nextprotoneg arg - enable NPN extension, considering named protocols supported (comma-separated list)
 -legacy_renegotiation - enable use of legacy renegotiation (dangerous)
 -use_srtp profiles - Offer SRTP key management with a colon-separated profile list
 -keymatexport label   - Export keying material using label
 -keymatexportlen len  - Export len bytes of keying material (default 20)
 
 
D:\OpenSSL\1_0_0_1dll\bin>openssl s_client -connect 109.120.162.1:443 -servername kkmspb.ru -tls1
Loading 'screen' into random state - done
CONNECTED(000001E0)
10888:error:1409442E:SSL routines:SSL3_READ_BYTES:tlsv1 alert protocol version:.\ssl\s3_pkt.c:1300:SSL alert number 70
10888:error:1409E0E5:SSL routines:SSL3_WRITE_BYTES:ssl handshake failure:.\ssl\s3_pkt.c:637:
---
no peer certificate available
---
No client certificate CA names sent
---
SSL handshake has read 7 bytes and written 0 bytes
---
New, (NONE), Cipher is (NONE)
Secure Renegotiation IS NOT supported
Compression: NONE
Expansion: NONE
SSL-Session:
    Protocol  : TLSv1
    Cipher    : 0000
    Session-ID:
    Session-ID-ctx:
    Master-Key:
    Key-Arg   : None
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    Start Time: 1633093436
    Timeout   : 7200 (sec)
    Verify return code: 0 (ok)
---
 
D:\OpenSSL\1_0_0_1dll\bin>openssl s_client -connect 109.120.162.1:443 -servername kkmspb.ru -tls1_1
Loading 'screen' into random state - done
CONNECTED(000001B8)
9116:error:1409442E:SSL routines:SSL3_READ_BYTES:tlsv1 alert protocol version:.\ssl\s3_pkt.c:1300:SSL alert number 70
9116:error:1409E0E5:SSL routines:SSL3_WRITE_BYTES:ssl handshake failure:.\ssl\s3_pkt.c:637:
---
no peer certificate available
---
No client certificate CA names sent
---
SSL handshake has read 7 bytes and written 0 bytes
---
New, (NONE), Cipher is (NONE)
Secure Renegotiation IS NOT supported
Compression: NONE
Expansion: NONE
SSL-Session:
    Protocol  : TLSv1.1
    Cipher    : 0000
    Session-ID:
    Session-ID-ctx:
    Master-Key:
    Key-Arg   : None
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    Start Time: 1633093500
    Timeout   : 7200 (sec)
    Verify return code: 0 (ok)
---


D:\OpenSSL\1_0_0_1dll\bin>openssl s_client -connect 109.120.162.1:443 -servername kkmspb.ru -tls1_2
Loading 'screen' into random state - done
CONNECTED(000001F4)
depth=2 C = US, O = Internet Security Research Group, CN = ISRG Root X1
verify error:num=20:unable to get local issuer certificate
verify return:0
---
Certificate chain
 0 s:/CN=kkmspb.ru
   i:/C=US/O=Let's Encrypt/CN=R3
 1 s:/C=US/O=Let's Encrypt/CN=R3
   i:/C=US/O=Internet Security Research Group/CN=ISRG Root X1
 2 s:/C=US/O=Internet Security Research Group/CN=ISRG Root X1
   i:/O=Digital Signature Trust Co./CN=DST Root CA X3
---
Server certificate
-----BEGIN CERTIFICATE-----
MIIFJzCCBA+gAwIBAgISA/R0611YnD8Wihy1Qm3pF/H8MA0GCSqGSIb3DQEBCwUA
MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD
EwJSMzAeFw0yMTA5MDgxNTI5NTRaFw0yMTEyMDcxNTI5NTNaMBQxEjAQBgNVBAMT
CWtrbXNwYi5ydTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALY39kuS
g619F4MvOkNqPoRcoB8xwlkmjRfpwp9mtqvV4aVrL9CKcviLG4bAN0sDkhkIZUfW
RHteDb3neao0SiJe7cAx7EvnI96L/YYAtSFmf6F4FH6MzXeSmObhVmZvVagRQLJ1
4MMS3nyG21UGR1rVcAViet00mztqOqhk2wXz+6nGGnKGhB2cIox/T/BA4ukpeZQy
PAbgcieVG/l4DWt1aPved/aOjERntUJMLRRbET6Ai36sGxQYIea7Q82WQzvjHqVG
Sfh+j1Qo8zpRX0tuAmGvwmWGOmBJcCn5FSHCeW9A/4/n3IT5AhJWuphMVppCbw6O
DBuKVBSY5mZf49UCAwEAAaOCAlMwggJPMA4GA1UdDwEB/wQEAwIFoDAdBgNVHSUE
FjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwDAYDVR0TAQH/BAIwADAdBgNVHQ4EFgQU
to3eoC2xthyNIeSZDcBVvfTAwBYwHwYDVR0jBBgwFoAUFC6zF7dYVsuuUAlA5h+v
nYsUwsYwVQYIKwYBBQUHAQEESTBHMCEGCCsGAQUFBzABhhVodHRwOi8vcjMuby5s
ZW5jci5vcmcwIgYIKwYBBQUHMAKGFmh0dHA6Ly9yMy5pLmxlbmNyLm9yZy8wIwYD
VR0RBBwwGoIJa2ttc3BiLnJ1gg13d3cua2ttc3BiLnJ1MEwGA1UdIARFMEMwCAYG
Z4EMAQIBMDcGCysGAQQBgt8TAQEBMCgwJgYIKwYBBQUHAgEWGmh0dHA6Ly9jcHMu
bGV0c2VuY3J5cHQub3JnMIIBBAYKKwYBBAHWeQIEAgSB9QSB8gDwAHYAb1N2rDHw
MRnYmQCkURX/dxUcEdkCwQApBo2yCJo32RMAAAF7xj6SigAABAMARzBFAiEAr7ok
QAzVN+lUiQJuj7AUlagSH+MeJ6zjjMVIaijLZSMCIGxjoDVjmm+ylZSuFcAfVmWC
zskgVXctgpilUi9rxYN0AHYA9lyUL9F3MCIUVBgIMJRWjuNNExkzv98MLyALzE7x
ZOMAAAF7xj6S1AAABAMARzBFAiEA1PusJdJEpf5XMteKYOndfHZwSrcuyz8K0kc0
WsIGy8ECIDBGWPNf7FuBPWuOH2H8BzyUt4v55+IqJtrSKteiqrN8MA0GCSqGSIb3
DQEBCwUAA4IBAQBPrSqRX90IIuKwwJKysbJ4y9hri+BCeyvCclOnJUSpVhortyA2
YBzCQA44MB64B9uWAIwaYR1j+ZPbglsDvWeyBbSh5ORh0EvV9xqe5rcthl0xWCg8
L3szvjomw0gdJWTznkRAfrVcc4BeZhMQnGP/dEY88WeWPnu36WCyC+HrH0ezkyN7
gSQsRau9SeuOhfPpsYOBcMPoHwyKc/R4XWiQbAt6XPqiR1d+jJhsKYTUE0Kv9XCv
OeTxm7P5JZ1xKLuzbfr1WsSlYy6uW/5hAmxmsMa0P1y0e+OqwP4lGMAMOTUojHJG
/H8ow+6vG0hrwUYf+u/hbwgpwUUcQMyZicgA
-----END CERTIFICATE-----
subject=/CN=kkmspb.ru
issuer=/C=US/O=Let's Encrypt/CN=R3
---
No client certificate CA names sent
---
SSL handshake has read 4705 bytes and written 435 bytes
---
New, TLSv1/SSLv3, Cipher is ECDHE-RSA-AES256-GCM-SHA384
Server public key is 2048 bit
Secure Renegotiation IS supported
Compression: NONE
Expansion: NONE
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : ECDHE-RSA-AES256-GCM-SHA384
    Session-ID: C3B2A8DB716A5AD80AA2227EC0012B1184C18ABDBEF5EE810D7688B642C9D7BA
    Session-ID-ctx:
    Master-Key: EDC549063047A40971A1A98D7A62B2CC8556EDFBA4792ABFAC3BCCF105C94A812093DB2A6226A6489E7A2CD2146172B5
    Key-Arg   : None
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 300 (seconds)
    TLS session ticket:
    0000 - 20 bd 55 02 65 28 d1 72-31 50 0a bb 49 98 9a dc    .U.e(.r1P..I...
    0010 - a8 5f 93 29 e7 31 fd a5-39 af 73 3d f9 d4 d8 67   ._.).1..9.s=...g
    0020 - c6 b2 b7 10 f7 cf 23 fe-86 6a da 00 c6 99 34 ef   ......#..j....4.
    0030 - ab 5e d0 09 ef 92 e2 e4-68 e6 60 4b ef 0f 10 25   .^......h.`K...%
    0040 - 61 90 f6 bb 0c 41 3d 27-98 67 72 5e 6f 81 b9 fb   a....A='.gr^o...
    0050 - 2f 38 09 44 01 5c 70 6a-25 b2 eb 82 67 04 12 32   /8.D.\pj%...g..2
    0060 - 73 ad 2c d5 ff 68 35 26-12 74 d5 1a d3 a0 43 09   s.,..h5&.t....C.
    0070 - 07 f4 3b ab b8 8c d2 d6-93 db b4 b4 63 d1 81 98   ..;.........c...
    0080 - 8d 70 be e8 0d bc fe c8-70 3f 72 7b 84 69 45 ac   .p......p?r{.iE.
    0090 - b5 b2 82 94 85 f2 74 6f-6c 28 cb 22 07 98 55 fd   ......tol(."..U.
    00a0 - 53 8d da 5d 31 75 f8 fc-3b 38 17 8d 76 9b b8 f2   S..]1u..;8..v...
    00b0 - 84 b6 d3 46 3a 09 8d 3e-d0 19 61 12 f2 cd 71 19   ...F:..>..a...q.

    Start Time: 1633093578
    Timeout   : 7200 (sec)
    Verify return code: 20 (unable to get local issuer certificate)
---