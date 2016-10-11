void setup() {
  Serial.begin(115200);
  Serial3.begin(19200);
  //send_test_SMS();
}

void loop() {
  delay(100);

  // Send AT commands via Serial Monitor.
  while (Serial3.available()) 
    Serial.write(Serial3.read());
  while (Serial.available()) 
      Serial3.write(Serial.read());
}

void send_test_SMS() {
    Serial3.print("AT+CMGF=1\r");
    delay(100);
    Serial3.println("AT+CMGS=\"+1555#######\"");
    delay(100);
    Serial3.println("Hello, World!");
    delay(100);
    Serial3.println((char)26);//the ASCII code of the ctrl+z is 26
    delay(100);
    Serial3.println();
    Serial.println("Test SMS sent.");
}

/* Available AT commands on this module
 * AT#CLS
 * AT&C
 * AT&D
 * AT&F
 * AT&S
 * AT&V
 * AT&W
 * AT*CELLLPSCELLLOCK
 * AT*PSCHRU
 * AT*PSCIPH
 * AT*PSCNAP
 * AT+*PSCPBS
 * AT*PSCPPSMEMCAP
 * AT*PSNTRG
 * AT*PSNWID
 * AT*PSOPNM
 * AT*PSPNNR
 * AT*PSPNNU
 * ELL
 * ATA
 * ATA53
 * ATATT
 * ATAUDG
 * ATAUTEST
 * ATB
 * ATCAAS
 * AT+CACM
 * AZERRING
 * ATCCALR
 * AT+CCFC
 * AT+CCID
 * AT+CCLK
 * ATCCODE
 * ATCCPD
 * ATG
 * ATCEXTBUT
 * ATCEXTERNTONE
 * ATCEXTHS
 * ATCFGRI
 * AT+CFUN
 * AT+CGACAT+CGMM
 * AT+CGMR
 * ATCGMSCLASS
 * AT+CGPADDR
 * AT+CGQMIN
 * AT+CGQREQ
 * ATCIPATS
 * ATCIPCCFG
 * ATCIPCLOSE
 * ATCIPCSGP
 * ATCIPDPDP
 * ATCIPHEAD
 * GTXT
 * ATCIPSHOWTP
 * ATCIPSHUT
 * ATCIPSPRT
 * ATCIPSRIP
 * ATCIPSTART
 * T+CLIR
 * ATCLNWPLMN
 * ATCLPORT
 * ATCLTS
 * AT+CLVL
 * AT+CMEC
 * AT+CMEE
 * +CMUT
 * AT+CMUX
 * ATCNETLIGHT
 * AT+CNETSCAN
 * ATCNITZNN
 * AT+CNMA
 * ATOWD
 * AT+CPRODFLAG
 * AT+CPUC
 * AT+CPWC
 * AT+CPWD
 * ATCQUICKPDP
 * AT+CRA
 * AT+CSCB
 * ATCSCLK
 * AT+CSCS
 * AT+CSDH
 * ATCSDT
 * ATCSGS
 * AT+CSGT
 * ATZR
 * ATCTZU
 * ATCUDHI
 * ATCUSACC
 * AT+CUSD
 * AT+CVHU
 * ATCWHITELIST
 * GET
 * ATFTPGETNAME
 * ATFTPGETPATH
 * ATFTPMODE
 * ATFTPPORT
 * ATFTPPUT
 * OUT
 * ATFTPTYPE
 * ATFTPUN
 * ATFTPV
 * AT+GCAP
 * AT+GMI
 * AT+GMM
 * AT+GMRATHTTPSTATUS
 * ATHTTPTERM
 * AT+HVOIC
 * ATI
 * AT+ICF
 * AT+IFC
 * AT+IPR
 * ATS7
 * ATS8
 * ATS95
 * ATSAPBR
 * ATSCLASS0
 * ATSGPIO
 * ATSIDET
 * ATSIMECHX
 * ATZ
 */
