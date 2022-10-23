/*
 * FreeRTOS V202012.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/*
 ****************************************************************************
 * NOTE!
 * This file is for ease of demonstration only.  Secret information should not
 * be pasted into the header file in production devices.  Do not paste
 * production secrets here!  Production devices should store secrets such as
 * private keys securely, such as within a secure element.  See our examples that
 * demonstrate how to use the PKCS #11 API for secure keys access.
 ****************************************************************************
 */

#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

/*
 * @brief PEM-encoded client certificate.
 *
 * @todo If you are running one of the FreeRTOS demo projects, set this
 * to the certificate that will be used for TLS client authentication.
 *
 * @note Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWjCCAkKgAwIBAgIVAJ/u9vxWF8ND2vyaOqkY0vcHfSrKMA0GCSqGSIb3DQEB\n"\
"CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n"\
"IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjEwMjIwNzI2\n"\
"MDNaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n"\
"dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC3/9dtULOmE+/lzjpQ\n"\
"pZtPTXiTkH7vWBRC0RF1KfhM/rBwq7u6qMS/va14jgDxtUyBlEQ/OISIq8Flv/VV\n"\
"n/UWHl/4gcIh/DtJu+l01eupZ/vi4e+xh+ZMdhtocpfNEYnwaDGsmwVPrqW4IGkU\n"\
"2OfH1GTNT5sMSIBpNUpCIIbNrLjJXJUSglK7N5G7fQsSIeYj+dmQiG/kNep2gOnJ\n"\
"jZeYfeEJzSDVCROXqzzNk6lIlSB1JjNH8WddzdBrCrsLCyv7rOFmVdlY3s+2IPeH\n"\
"t3eoXgZTb9JPY4Nmg10KEDietg985CgMDn7ou5a7oA+y22bxJumYdWrpn7Rwqexn\n"\
"EOHtAgMBAAGjYDBeMB8GA1UdIwQYMBaAFF7Xre26ZdMd28odB4lh/xkDt4MFMB0G\n"\
"A1UdDgQWBBSqBErS/yO4vHBCHEIC6O9sMD+cwTAMBgNVHRMBAf8EAjAAMA4GA1Ud\n"\
"DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAJKU+DSn8vxNGHzsu8GOMtZvv\n"\
"ozDu6Tq5OBN8UgLoT3keM93OlFwwjPtNZK4aDUDN0dqai38jpL+SJuJaFhhvQnAi\n"\
"+il/aJ6AV3QkMAodyXZAnexPa7Log7L6j0VHHpT1APfd00fxdCXKiJ/jn8SSOYMm\n"\
"DZSaiUlPZP1eE8i5LkqvASLmte6NNfdXIUQMuV90fNxNlJXT/dEV0bWU2VGS0uTg\n"\
"GaopdY0oEokXE7xBjghGgtDSz98ecbvnT+L57Njolfum8Oqq7PYnvfwHgmp3taNz\n"\
"Q0ihbM23Rkpqk9sCIa9LMYlMB2zggLMdR71FYcMUht1GzZxVmNCxUN4zhdeXuQ==\n"\
"-----END CERTIFICATE-----"

/*
 * @brief PEM-encoded issuer certificate for AWS IoT Just In Time Registration (JITR).
 *
 * @todo If you are using AWS IoT Just in Time Registration (JITR), set this to
 * the issuer (Certificate Authority) certificate of the client certificate above.
 *
 * @note This setting is required by JITR because the issuer is used by the AWS
 * IoT gateway for routing the device's initial request. (The device client
 * certificate must always be sent as well.) For more information about JITR, see:
 *  https://docs.aws.amazon.com/iot/latest/developerguide/jit-provisioning.html,
 *  https://aws.amazon.com/blogs/iot/just-in-time-registration-of-device-certificates-on-aws-iot/.
 *
 * If you're not using JITR, set below to NULL.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM    NULL

/*
 * @brief PEM-encoded client private key.
 *
 * @todo If you are running one of the FreeRTOS demo projects, set this
 * to the private key that will be used for TLS client authentication.
 * Please note pasting a key into the header file in this manner is for
 * convenience of demonstration only and should not be done in production.
 * Never past a production private key here!.  Production devices should
 * store keys securely, such as within a secure element.  Additionally,
 * we provide the corePKCS library that further enhances security by
 * enabling keys to be used without exposing them to software.
 *
 * @note Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----\n"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEpAIBAAKCAQEAt//XbVCzphPv5c46UKWbT014k5B+71gUQtERdSn4TP6wcKu7\n"\
"uqjEv72teI4A8bVMgZREPziEiKvBZb/1VZ/1Fh5f+IHCIfw7SbvpdNXrqWf74uHv\n"\
"sYfmTHYbaHKXzRGJ8GgxrJsFT66luCBpFNjnx9RkzU+bDEiAaTVKQiCGzay4yVyV\n"\
"EoJSuzeRu30LEiHmI/nZkIhv5DXqdoDpyY2XmH3hCc0g1QkTl6s8zZOpSJUgdSYz\n"\
"R/FnXc3Qawq7Cwsr+6zhZlXZWN7PtiD3h7d3qF4GU2/ST2ODZoNdChA4nrYPfOQo\n"\
"DA5+6LuWu6APsttm8SbpmHVq6Z+0cKnsZxDh7QIDAQABAoIBAHsCud1FRLVVQt7Z\n"\
"/raH4MslueS9h38v3WvGJeu0gWHIK+FHjpv91HtzrZOZLBxr3pgKrY2ulTxhx0vl\n"\
"B3mVFN8Ss4qKBWV/IYvr6unHUmPRNt65uetwNZEMrMopQj9A6H0my37frK9WzUfJ\n"\
"szbSxDIeVr3D6J5Pojmz/M80u6qoGioFV0V4XZfXSXz2zuuqIxE8/gRxH89F060x\n"\
"tr/6aWWopAoeAUg3wpJnHZnCJM+C9DwbMZbsI7Mt4aXIFtKezGJTEaBncHkUTO+x\n"\
"su2YqkYcfOpdNOMzEVr34suRK+azm1YA4yXelyI6iEY853JRpHZWH6oyqQzDLKvD\n"\
"xg0jzakCgYEA3T1oFZH7SF24fMYMXgvMVjRUhZbLFhWjN8vLWJVGR+aUdEWoAmsi\n"\
"pmp0E5CMLWfQRvYOj7+VVfnIZyQOMjhjSDSsckgb3vPXZsNgJDTKhZShv2y/voD8\n"\
"N/7CdWodEz4q4DAHWEDHVjdjUsmI4a98RxtLTffDOf4dLZAjSqAmSbMCgYEA1OiR\n"\
"UD13DFPEypbOnk9CRsZ0AbwFPXpzCR+y8DAZlqyDRQq3DdqId+Q6X+k1cNBIHgP8\n"\
"daFbaO7Hw5Y6qgSaXQuun1AwRheMPe7YsiP2fl8vnAPmyGVKUoKQqtayocvSZcgT\n"\
"b5ep2d4UcDTzGJAJ1kwIVE7A62ecgfOtIDwpFd8CgYEAsKpxbBAXVZEpWdGYXJ0V\n"\
"PZ0qBUcFwwviOxLsvT7uUUoKL9LTt6Kvl64YJOtfVH66rX+c3yMAcBg29E2xXF70\n"\
"wNr2/YchYmbbEb9gDWlucz7d7os7jjdXsKspwzLKJuyUtlMD+nA3/VvbX2d5e6Zz\n"\
"GiDsgEUhyzRlPlYEKHo8OMsCgYEA0Yh4ypFTQkyG1iKJAgBa57CTpslWFuUVpZsO\n"\
"zZdo94KcRix/byDtQaDZWl73eylgcDnYEiRVA/ZLn0+QOJcDHCNNHfkbKUAvgxw3\n"\
"I0qFYmVnQ5ILZJlbBcz9d0SI1Pb0/7pidma6gHIxhyR1Qm0vYTm+0MoYzxRPUQ1y\n"\
"CtFqVd0CgYBJoCYJGzPMn+8+QZqxvz4UCYgqckvwGmljmIljcYJ6pfTj098WlfFK\n"\
"8YzbJBBmH2Z04LBTmwXeTUdfffLxkmK/Td3VEWnJpLR4Ij4mPOUHyQnpPZPLYgUG\n"\
"ocNypFhdXLvzbLM2zAVCyMtOYXQQi5YI7XR5EdooqJnEW0sjLiwGVg==\n"\
"-----END RSA PRIVATE KEY-----"

#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
