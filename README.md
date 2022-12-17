# Qt_BT_ELM327
Connect to ELM327 from qt application


ATZ
ATAL
ATCAF0
ATV1
ATBI
ATSP6
ATSH79B

at fc sh 79b
at fc sd 30 00 20 FF FF FF FF FF
at fc sm 1

ATCEA
079B
02 21 01 FF FF FF FF FF
022101FFFFFFFFFF
022102FFFFFFFFFF


Read after LeafSpy setts
: ATDP
(AA:BB:CC:11:22:33): IS
(AA:BB:CC:11:22:33): O 15765-4 (CAN 11/500)

>

The
ELM327 will automatically send this response for you
as long as the CAN Flow Control option is enabled
(CFC1), which it is by default.
In order to provide complete control over the
sending of Flow Control messages and their content,
the ELM327 defines several AT FC commands.

The way in which the ELM327 responds to a First
Frame message is determined by the Flow Control
‘mode’, as set by the AT FC SM command. There are
currently three modes, as shown in the chart. The
default Flow Control mode is number ‘0’, meaning that
the ELM327 will do everything for you.


: ATPPS
(AA:BB:CC:11:22:33): 
00:FF F  01:FF F  02:FF F  03:32 F
04:01 F  05:FF F  06:F1 F  07:09 F
08:FF F  09:00 F  0A:0A F  0B:FF F
0C:68 F  0D:0D F  0E:9A F  0F:FF F
10:0D F  11:00 F  12:FF F  13:32 F
14:FF F  15:0A F  16:FF F
(AA:BB:CC:11:22:33):   17:92 F
18:00 F  19:28 F  1A:FF F  1B:FF F
1C:FF F  1D:FF F  1E:FF F  1F:FF F
20:FF F  21:FF F  22
(AA:BB:CC:11:22:33): :FF F  23:FF F
24:00 F  25:00 F  26:00 F  27:FF F
28:FF F  29:FF F  2A:38 F  2B:02 F
2C:E0 F  2D:04 
(AA:BB:CC:11:22:33): F  2E:80 F  2F:0A F

>


after power reset

(AA:BB:CC:11:22:33): ATPPS

(AA:BB:CC:11:22:33): 
00:FF F  01:FF F  02:FF F  03:32 F
04:01 F  05:FF F  06:F1 F  07:09 F
08:FF F  09:00 F  0A:0A F  0B:FF F
0C:68 F  0D:0D F  0E:9A F  0F:FF F
10:0D F  11:00 F  12:FF F  13:32 F
14:FF F  15:0A F  16:FF F  17:92 F
18:00 F  19:28 F  1A:FF F  1B:FF F
1C:FF F  1D:FF F  1E:FF F  1F:FF F
20:FF F  21:FF F  22
(AA:BB:CC:11:22:33): :FF F  23:FF F
24:00 F  25:00 F  26:00 F  27:FF F
28:FF F  29:FF F  2A:38 F  2B:02 F
2C:E0 F  2D:04 
(AA:BB:CC:11:22:33): F  2E:80 F  2F:0A F

>



>at h1
OK

>at d1
OK

>at sh 79b
OK

>at fc sh 79b
OK

>at fc sd 30 00 20
OK

>at fc sm 1
OK

>21 02
7BB 8 10 C6 61 02 0F C6 0F CD
7BB 8 21 0F CC 0F C4 0F D5 0F
7BB 8 22 D1 0F CB 0F C4 0F D1
7BB 8 23 0F C6 0F C8 0F C4 0F
7BB 8 24 D2 0F D6 0F D2 0F D3
7BB 8 25 0F D2 0F C8 0F C8 0F
7BB 8 26 C9 0F D2 0F C8 0F CD
7BB 8 27 0F C4 0F D1 0F CD 0F
7BB 8 28 CC 0F C8 0F CD 0F D2
7BB 8 29 0F CD 0F D2 0F CF 0F
7BB 8 2A CF 0F D4 0F D2 0F C6
7BB 8 2B 0F CB 0F CB 0F C8 0F
7BB 8 2C C4 0F C4 0F C8 0F C4
7BB 8 2D 0F D1 0F CF 0F D5 0F
7BB 8 2E D1 0F CF 0F D1 0F D5
7BB 8 2F 0F C8 0F D4 0F D0 0F
7BB 8 20 D4 0F D1 0F D7 0F D2
7BB 8 21 0F C8 0F CD 0F C3 0F
7BB 8 22 D2 0F C9 0F CE 0F C4
7BB 8 23 0F CD 0F C4 0F C8 0F
7BB 8 24 CD 0F CD 0F CD 0F CD
7BB 8 25 0F CC 0F CC 0F CB 0F
7BB 8 26 C8 0F C4 0F CD 0F C3
7BB 8 27 0F C9 0F CF 0F CF 0F
7BB 8 28 D5 0F CD 0F D5 0F D1
7BB 8 29 0F DA 0F C8 0F CD 0F
7BB 8 2A CD 0F D1 0F D6 0F C8
7BB 8 2B 0F CD 0F D1 0F C1 97