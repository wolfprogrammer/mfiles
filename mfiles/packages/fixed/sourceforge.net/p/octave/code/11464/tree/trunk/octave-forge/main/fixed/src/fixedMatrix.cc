<!DOCTYPE html>
<!-- Server: sfn-web-1 -->


  










<!--[if lt IE 7 ]> <html lang="en" class="no-js ie6"> <![endif]-->
<!--[if IE 7 ]>    <html lang="en" class="no-js ie7"> <![endif]-->
<!--[if IE 8 ]>    <html lang="en" class="no-js ie8"> <![endif]-->
<!--[if IE 9 ]>    <html lang="en" class="no-js ie9"> <![endif]-->
<!--[if (gt IE 9)|!(IE)]>--> <html lang="en" class="no-js"> <!--<![endif]-->
  <head>
    <meta content="text/html; charset=UTF-8" http-equiv="content-type"/>
    <title>
  Octave Forge / Code /
  [r11464]
  /trunk/octave-forge/main/fixed/src/fixedMatrix.cc
</title>
    

<script src="http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/js/sftheme/modernizr.custom.90514.js"></script>

<script src="http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/js/sftheme/jquery-1.8.0.min.js"></script>

<script src="http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/js/sftheme/header.js"></script>
<!--[if lt IE 7 ]>
  <script src="http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/js/sftheme/dd_belatedpng.js"></script>
  <script> DD_belatedPNG.fix('img, .png_bg'); //fix any <img> or .png_bg background-images </script>
<![endif]-->
<link href='//fonts.googleapis.com/css?family=Ubuntu:regular' rel='stylesheet' type='text/css'>
<style type="text/css">
    @font-face {
        font-family: "Pictos";
        src: url('http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/css/fonts/sftheme/pictos-web.eot');
        src: local("☺"), url('http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/css/fonts/sftheme/pictos-web.woff') format('woff'), url('http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/css/fonts/sftheme/pictos-web.ttf') format('truetype'), url('http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/css/fonts/sftheme/pictos-web.svg') format('svg');
    }
</style>
    <script type="text/javascript">
            /*jslint onevar: false, nomen: false, evil: true, css: true, plusplus: false, white: false, forin: true, on: true, immed: false */
            /*global confirm, alert, unescape, window, jQuery, $, net, COMSCORE */
    </script>
    
      <!-- ew:head_css -->

    
      <link rel="stylesheet"
                type="text/css"
                href="http://a.fsdn.com/allura/nf/1354307686/_ew_/_slim/css?href=allura%2Fcss%2Fforge%2Fhilite.css"
                >
    
      <link rel="stylesheet"
                type="text/css"
                href="http://a.fsdn.com/allura/nf/1354307686/_ew_/theme/sftheme/css/forge.css"
                >
    
      
<!-- /ew:head_css -->

    
    
    
      <!-- ew:head_js -->

    
      
<!-- /ew:head_js -->

    
    

    
      <style type="text/css">
        #page-body.project---init-- #top_nav { display: none; }
#page-body.project---init-- #nav_menu_holder { display: none; margin-bottom: 0; }
#page-body.project---init-- #content_base {margin-top: 0; }
      </style>
    
    
    <link rel="alternate" type="application/rss+xml" title="RSS" href="/p/octave/code/feed.rss"/>
    <link rel="alternate" type="application/atom+xml" title="Atom" href="/p/octave/code/feed.atom"/>

      <style>.XRaocbENWSEyFkmqfGwSkU { display:none }</style>

    
    
    
    


<script type="text/javascript">
    var _gaq = _gaq || [];

    function _add_tracking(prefix, tracking_id, send_user) {
        _gaq.push([prefix+'._setAccount', tracking_id]);
        _gaq.push([prefix+'._setCustomVar', 1, 'Page Type', 'SVN', 3]);_gaq.push([prefix+'._trackPageview']);
    }
      _add_tracking('sfnt1', 'UA-32013-6', true);
      _add_tracking('sfnt2', 'UA-36130941-1', true);
    

    (function() {
        var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
        ga.src = ('https:' === document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
    })();
</script>
  </head>

  <body id="forge">
    
      <!-- ew:body_top_js -->

    
      
<!-- /ew:body_top_js -->

    
    
<header id="site-header">
    <div class="wrapper">
        <a href="/" class="logo">
            <span>SourceForge</span>
        </a>
        
        <form method="get" action="/directory/">
            <input type="text" id="words" name="q" placeholder="Search">
        </form>
        
        <!--Switch to {language}-->
        <nav id="nav-site">
            <a href="/directory/" title="Browse our software.">Browse</a>
            <a href="/blog/" title="Read the latest news from the SF HQ.">Blog</a>
            <a href="/support" title="Contact us for help and feedback.">Help</a>
        </nav>
        <nav id="nav-account">
            
              <div class="logged_out">
                <a href="/account/login.php">Log In</a>
                <span>or</span>
                <a href="https://sourceforge.net/user/registration/">Join</a>
              </div>
            
        </nav>
        
    </div>
</header>
<header id="site-sec-header">
    <div class="wrapper">
        <nav id="nav-hubs">
            <h4>Solution Centers</h4>
            <a href="http://ibmsmartercommerce.sourceforge.net/">Smarter Commerce</a>
            <a href="http://goparallel.sourceforge.net/">Go Parallel</a>
            <a href="http://html5center.sourceforge.net/">HTML5</a>
            <a href="http://ibmsmarteritservices.sourceforge.net/">Smarter IT</a>
        </nav>
        <nav id="nav-collateral">
            <a href="http://library.geeknetmedia.com">Resources</a>
            
            <a href="">Newsletters</a>
            
        </nav>
    </div>
</header>
    
    <section id="page-body" class=" neighborhood-Projects project-octave mountpoint-code">
	  <div class="grid-24" id="nav_menu_holder">
            
            


  
  <a href="/p/octave/">
    
      <img src="/p/octave//icon?2012-09-22 21:52:49+00:00" class="project_icon" alt="Project Logo">
    
	<h1 class="project_title">
      
        Octave Forge
      
	</h1>
	</a>

            
      </div>
      <div id="top_nav" class="">
        
        
  
    <a href="/projects/octave/" class="ui-icon-tool-summary">
      Summary
      
        
      
    </a>
	
    <a href="/projects/octave/files/" class="ui-icon-tool-files">
      Files
      
        
      
    </a>
	
    <a href="/p/octave/mailman/" class="ui-icon-tool-mailman">
      Mailing Lists
      
        
      
    </a>
	
    <a href="/p/octave/code/" class="ui-icon-tool-svn">
      Code
      
        
          <span class="diamond"></span>
        
      
    </a>
	
    <a href="/p/octave/package-releases/" class="ui-icon-tool-tickets">
      Package Releases
      
        
      
    </a>
	
    <a href="/p/octave/feature-requests/" class="ui-icon-tool-tickets">
      Feature Requests
      
        
      
    </a>
	
    <a href="/p/octave/bugs/" class="ui-icon-tool-tickets">
      Bugs
      
        
      
    </a>
	
    <a href="/p/octave/discussion/" class="ui-icon-tool-discussion">
      Discussion
      
        
      
    </a>
	
	<div style="clear:both"></div>

        
      </div>
      <div id="content_base">
			  
			    
          


<div id="sidebar">
  
    <div>&nbsp;</div>
  
    
    
      
        
    
      <ul class="sidebarmenu">
      
    
    <li>
      <a href="/p/octave/code/commit_browser"><b data-icon="o" class="ico ico-folder"></b> <span>Browse Commits</span></a>
    </li>
  
      
    
    
      </ul>
      
    
    
</div>
          
          
			  
			  
          
        
        <div class="grid-20 pad">
          <h2 class="dark title">
<a href="/p/octave/code/11464/">[r11464]</a>:

  
  
    <a href="./../../../../">trunk</a> /
    
  
    <a href="./../../../">octave-forge</a> /
    
  
    <a href="./../../">main</a> /
    
  
    <a href="./../">fixed</a> /
    
  
    <a href="./">src</a> /
    
  
 fixedMatrix.cc

            <!-- actions -->
            <small>
            
<a href="/p/octave/code/11464/log/">
  <b data-icon="N" class="ico ico-history" title="History"> </b> History
</a>

            </small>
            <!-- /actions -->
          </h2>
		
          <div>
            
  

            
  

  

  
    <p><a href="?format=raw">Download this file</a></p>
    <div class="clip grid-19">
      <h3>
        <span class="ico-l"><b data-icon="n" class="ico ico-table"></b> fixedMatrix.cc</span>
        &nbsp;&nbsp;
        1457 lines (1196 with data), 31.1 kB
      </h3>
      
        <table class="codehilitetable"><tr><td class="linenos"><div class="linenodiv"><pre>   1
   2
   3
   4
   5
   6
   7
   8
   9
  10
  11
  12
  13
  14
  15
  16
  17
  18
  19
  20
  21
  22
  23
  24
  25
  26
  27
  28
  29
  30
  31
  32
  33
  34
  35
  36
  37
  38
  39
  40
  41
  42
  43
  44
  45
  46
  47
  48
  49
  50
  51
  52
  53
  54
  55
  56
  57
  58
  59
  60
  61
  62
  63
  64
  65
  66
  67
  68
  69
  70
  71
  72
  73
  74
  75
  76
  77
  78
  79
  80
  81
  82
  83
  84
  85
  86
  87
  88
  89
  90
  91
  92
  93
  94
  95
  96
  97
  98
  99
 100
 101
 102
 103
 104
 105
 106
 107
 108
 109
 110
 111
 112
 113
 114
 115
 116
 117
 118
 119
 120
 121
 122
 123
 124
 125
 126
 127
 128
 129
 130
 131
 132
 133
 134
 135
 136
 137
 138
 139
 140
 141
 142
 143
 144
 145
 146
 147
 148
 149
 150
 151
 152
 153
 154
 155
 156
 157
 158
 159
 160
 161
 162
 163
 164
 165
 166
 167
 168
 169
 170
 171
 172
 173
 174
 175
 176
 177
 178
 179
 180
 181
 182
 183
 184
 185
 186
 187
 188
 189
 190
 191
 192
 193
 194
 195
 196
 197
 198
 199
 200
 201
 202
 203
 204
 205
 206
 207
 208
 209
 210
 211
 212
 213
 214
 215
 216
 217
 218
 219
 220
 221
 222
 223
 224
 225
 226
 227
 228
 229
 230
 231
 232
 233
 234
 235
 236
 237
 238
 239
 240
 241
 242
 243
 244
 245
 246
 247
 248
 249
 250
 251
 252
 253
 254
 255
 256
 257
 258
 259
 260
 261
 262
 263
 264
 265
 266
 267
 268
 269
 270
 271
 272
 273
 274
 275
 276
 277
 278
 279
 280
 281
 282
 283
 284
 285
 286
 287
 288
 289
 290
 291
 292
 293
 294
 295
 296
 297
 298
 299
 300
 301
 302
 303
 304
 305
 306
 307
 308
 309
 310
 311
 312
 313
 314
 315
 316
 317
 318
 319
 320
 321
 322
 323
 324
 325
 326
 327
 328
 329
 330
 331
 332
 333
 334
 335
 336
 337
 338
 339
 340
 341
 342
 343
 344
 345
 346
 347
 348
 349
 350
 351
 352
 353
 354
 355
 356
 357
 358
 359
 360
 361
 362
 363
 364
 365
 366
 367
 368
 369
 370
 371
 372
 373
 374
 375
 376
 377
 378
 379
 380
 381
 382
 383
 384
 385
 386
 387
 388
 389
 390
 391
 392
 393
 394
 395
 396
 397
 398
 399
 400
 401
 402
 403
 404
 405
 406
 407
 408
 409
 410
 411
 412
 413
 414
 415
 416
 417
 418
 419
 420
 421
 422
 423
 424
 425
 426
 427
 428
 429
 430
 431
 432
 433
 434
 435
 436
 437
 438
 439
 440
 441
 442
 443
 444
 445
 446
 447
 448
 449
 450
 451
 452
 453
 454
 455
 456
 457
 458
 459
 460
 461
 462
 463
 464
 465
 466
 467
 468
 469
 470
 471
 472
 473
 474
 475
 476
 477
 478
 479
 480
 481
 482
 483
 484
 485
 486
 487
 488
 489
 490
 491
 492
 493
 494
 495
 496
 497
 498
 499
 500
 501
 502
 503
 504
 505
 506
 507
 508
 509
 510
 511
 512
 513
 514
 515
 516
 517
 518
 519
 520
 521
 522
 523
 524
 525
 526
 527
 528
 529
 530
 531
 532
 533
 534
 535
 536
 537
 538
 539
 540
 541
 542
 543
 544
 545
 546
 547
 548
 549
 550
 551
 552
 553
 554
 555
 556
 557
 558
 559
 560
 561
 562
 563
 564
 565
 566
 567
 568
 569
 570
 571
 572
 573
 574
 575
 576
 577
 578
 579
 580
 581
 582
 583
 584
 585
 586
 587
 588
 589
 590
 591
 592
 593
 594
 595
 596
 597
 598
 599
 600
 601
 602
 603
 604
 605
 606
 607
 608
 609
 610
 611
 612
 613
 614
 615
 616
 617
 618
 619
 620
 621
 622
 623
 624
 625
 626
 627
 628
 629
 630
 631
 632
 633
 634
 635
 636
 637
 638
 639
 640
 641
 642
 643
 644
 645
 646
 647
 648
 649
 650
 651
 652
 653
 654
 655
 656
 657
 658
 659
 660
 661
 662
 663
 664
 665
 666
 667
 668
 669
 670
 671
 672
 673
 674
 675
 676
 677
 678
 679
 680
 681
 682
 683
 684
 685
 686
 687
 688
 689
 690
 691
 692
 693
 694
 695
 696
 697
 698
 699
 700
 701
 702
 703
 704
 705
 706
 707
 708
 709
 710
 711
 712
 713
 714
 715
 716
 717
 718
 719
 720
 721
 722
 723
 724
 725
 726
 727
 728
 729
 730
 731
 732
 733
 734
 735
 736
 737
 738
 739
 740
 741
 742
 743
 744
 745
 746
 747
 748
 749
 750
 751
 752
 753
 754
 755
 756
 757
 758
 759
 760
 761
 762
 763
 764
 765
 766
 767
 768
 769
 770
 771
 772
 773
 774
 775
 776
 777
 778
 779
 780
 781
 782
 783
 784
 785
 786
 787
 788
 789
 790
 791
 792
 793
 794
 795
 796
 797
 798
 799
 800
 801
 802
 803
 804
 805
 806
 807
 808
 809
 810
 811
 812
 813
 814
 815
 816
 817
 818
 819
 820
 821
 822
 823
 824
 825
 826
 827
 828
 829
 830
 831
 832
 833
 834
 835
 836
 837
 838
 839
 840
 841
 842
 843
 844
 845
 846
 847
 848
 849
 850
 851
 852
 853
 854
 855
 856
 857
 858
 859
 860
 861
 862
 863
 864
 865
 866
 867
 868
 869
 870
 871
 872
 873
 874
 875
 876
 877
 878
 879
 880
 881
 882
 883
 884
 885
 886
 887
 888
 889
 890
 891
 892
 893
 894
 895
 896
 897
 898
 899
 900
 901
 902
 903
 904
 905
 906
 907
 908
 909
 910
 911
 912
 913
 914
 915
 916
 917
 918
 919
 920
 921
 922
 923
 924
 925
 926
 927
 928
 929
 930
 931
 932
 933
 934
 935
 936
 937
 938
 939
 940
 941
 942
 943
 944
 945
 946
 947
 948
 949
 950
 951
 952
 953
 954
 955
 956
 957
 958
 959
 960
 961
 962
 963
 964
 965
 966
 967
 968
 969
 970
 971
 972
 973
 974
 975
 976
 977
 978
 979
 980
 981
 982
 983
 984
 985
 986
 987
 988
 989
 990
 991
 992
 993
 994
 995
 996
 997
 998
 999
1000
1001
1002
1003
1004
1005
1006
1007
1008
1009
1010
1011
1012
1013
1014
1015
1016
1017
1018
1019
1020
1021
1022
1023
1024
1025
1026
1027
1028
1029
1030
1031
1032
1033
1034
1035
1036
1037
1038
1039
1040
1041
1042
1043
1044
1045
1046
1047
1048
1049
1050
1051
1052
1053
1054
1055
1056
1057
1058
1059
1060
1061
1062
1063
1064
1065
1066
1067
1068
1069
1070
1071
1072
1073
1074
1075
1076
1077
1078
1079
1080
1081
1082
1083
1084
1085
1086
1087
1088
1089
1090
1091
1092
1093
1094
1095
1096
1097
1098
1099
1100
1101
1102
1103
1104
1105
1106
1107
1108
1109
1110
1111
1112
1113
1114
1115
1116
1117
1118
1119
1120
1121
1122
1123
1124
1125
1126
1127
1128
1129
1130
1131
1132
1133
1134
1135
1136
1137
1138
1139
1140
1141
1142
1143
1144
1145
1146
1147
1148
1149
1150
1151
1152
1153
1154
1155
1156
1157
1158
1159
1160
1161
1162
1163
1164
1165
1166
1167
1168
1169
1170
1171
1172
1173
1174
1175
1176
1177
1178
1179
1180
1181
1182
1183
1184
1185
1186
1187
1188
1189
1190
1191
1192
1193
1194
1195
1196
1197
1198
1199
1200
1201
1202
1203
1204
1205
1206
1207
1208
1209
1210
1211
1212
1213
1214
1215
1216
1217
1218
1219
1220
1221
1222
1223
1224
1225
1226
1227
1228
1229
1230
1231
1232
1233
1234
1235
1236
1237
1238
1239
1240
1241
1242
1243
1244
1245
1246
1247
1248
1249
1250
1251
1252
1253
1254
1255
1256
1257
1258
1259
1260
1261
1262
1263
1264
1265
1266
1267
1268
1269
1270
1271
1272
1273
1274
1275
1276
1277
1278
1279
1280
1281
1282
1283
1284
1285
1286
1287
1288
1289
1290
1291
1292
1293
1294
1295
1296
1297
1298
1299
1300
1301
1302
1303
1304
1305
1306
1307
1308
1309
1310
1311
1312
1313
1314
1315
1316
1317
1318
1319
1320
1321
1322
1323
1324
1325
1326
1327
1328
1329
1330
1331
1332
1333
1334
1335
1336
1337
1338
1339
1340
1341
1342
1343
1344
1345
1346
1347
1348
1349
1350
1351
1352
1353
1354
1355
1356
1357
1358
1359
1360
1361
1362
1363
1364
1365
1366
1367
1368
1369
1370
1371
1372
1373
1374
1375
1376
1377
1378
1379
1380
1381
1382
1383
1384
1385
1386
1387
1388
1389
1390
1391
1392
1393
1394
1395
1396
1397
1398
1399
1400
1401
1402
1403
1404
1405
1406
1407
1408
1409
1410
1411
1412
1413
1414
1415
1416
1417
1418
1419
1420
1421
1422
1423
1424
1425
1426
1427
1428
1429
1430
1431
1432
1433
1434
1435
1436
1437
1438
1439
1440
1441
1442
1443
1444
1445
1446
1447
1448
1449
1450
1451
1452
1453
1454
1455
1456</pre></div></td><td class="code"><div class="codehilite"><pre><div id="l1" class="code_block"><span class="cm">/*</span>
</div><div id="l2" class="code_block">
</div><div id="l3" class="code_block"><span class="cm">Copyright (C) 2003 Motorola Inc</span>
</div><div id="l4" class="code_block"><span class="cm">Copyright (C) 2003 David Bateman</span>
</div><div id="l5" class="code_block">
</div><div id="l6" class="code_block"><span class="cm">This program is free software; you can redistribute it and/or modify it</span>
</div><div id="l7" class="code_block"><span class="cm">under the terms of the GNU General Public License as published by the</span>
</div><div id="l8" class="code_block"><span class="cm">Free Software Foundation; either version 2, or (at your option) any</span>
</div><div id="l9" class="code_block"><span class="cm">later version.</span>
</div><div id="l10" class="code_block">
</div><div id="l11" class="code_block"><span class="cm">This program is distributed in the hope that it will be useful, but WITHOUT</span>
</div><div id="l12" class="code_block"><span class="cm">ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or</span>
</div><div id="l13" class="code_block"><span class="cm">FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License</span>
</div><div id="l14" class="code_block"><span class="cm">for more details.</span>
</div><div id="l15" class="code_block">
</div><div id="l16" class="code_block"><span class="cm">You should have received a copy of the GNU General Public License</span>
</div><div id="l17" class="code_block"><span class="cm">along with this program; see the file COPYING.  If not, see</span>
</div><div id="l18" class="code_block"><span class="cm">&lt;http://www.gnu.org/licenses/&gt;.</span>
</div><div id="l19" class="code_block">
</div><div id="l20" class="code_block"><span class="cm">In addition to the terms of the GPL, you are permitted to link</span>
</div><div id="l21" class="code_block"><span class="cm">this program with any Open Source program, as defined by the</span>
</div><div id="l22" class="code_block"><span class="cm">Open Source Initiative (www.opensource.org)</span>
</div><div id="l23" class="code_block">
</div><div id="l24" class="code_block"><span class="cm">*/</span>
</div><div id="l25" class="code_block">
</div><div id="l26" class="code_block"><span class="cp">#include &lt;iostream&gt;</span>
</div><div id="l27" class="code_block">
</div><div id="l28" class="code_block"><span class="cp">#include &lt;octave/config.h&gt;</span>
</div><div id="l29" class="code_block"><span class="cp">#include &lt;octave/lo-error.h&gt;</span>
</div><div id="l30" class="code_block"><span class="cp">#include &lt;octave/lo-utils.h&gt;</span>
</div><div id="l31" class="code_block"><span class="cp">#include &lt;octave/lo-error.h&gt;</span>
</div><div id="l32" class="code_block"><span class="cp">#include &lt;octave/error.h&gt;</span>
</div><div id="l33" class="code_block"><span class="cp">#include &lt;octave/dMatrix.h&gt;</span>
</div><div id="l34" class="code_block"><span class="cp">#include &lt;octave/gripes.h&gt;</span>
</div><div id="l35" class="code_block"><span class="cp">#include &lt;octave/ops.h&gt;</span>
</div><div id="l36" class="code_block"><span class="cp">#include &lt;octave/quit.h&gt;</span>
</div><div id="l37" class="code_block">
</div><div id="l38" class="code_block"><span class="cp">#include &quot;fixedColVector.h&quot;</span>
</div><div id="l39" class="code_block"><span class="cp">#include &quot;fixedRowVector.h&quot;</span>
</div><div id="l40" class="code_block"><span class="cp">#include &quot;fixedMatrix.h&quot;</span>
</div><div id="l41" class="code_block"><span class="cp">#include &quot;fixedCMatrix.h&quot;</span>
</div><div id="l42" class="code_block">
</div><div id="l43" class="code_block"><span class="cp">#include &quot;fixed-inline.cc&quot;</span>
</div><div id="l44" class="code_block">
</div><div id="l45" class="code_block"><span class="c1">// Fixed Point Matrix class.</span>
</div><div id="l46" class="code_block">
</div><div id="l47" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">)</span>
</div><div id="l48" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l49" class="code_block"><span class="p">{</span>
</div><div id="l50" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l51" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l52" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l53" class="code_block">  <span class="p">}</span>
</div><div id="l54" class="code_block">
</div><div id="l55" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l56" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l57" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l58" class="code_block"><span class="p">}</span>
</div><div id="l59" class="code_block">
</div><div id="l60" class="code_block">
</div><div id="l61" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">)</span>
</div><div id="l62" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l63" class="code_block"><span class="p">{</span>
</div><div id="l64" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l65" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l66" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l67" class="code_block">  <span class="p">}</span>
</div><div id="l68" class="code_block">
</div><div id="l69" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l70" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l71" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l72" class="code_block"><span class="p">}</span>
</div><div id="l73" class="code_block">
</div><div id="l74" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">,</span>
</div><div id="l75" class="code_block">			  <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l76" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l77" class="code_block"><span class="p">{</span>
</div><div id="l78" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span>
</div><div id="l79" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l80" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l81" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l82" class="code_block">  <span class="p">}</span>
</div><div id="l83" class="code_block">
</div><div id="l84" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l85" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l86" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> 
</div><div id="l87" class="code_block">			       <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l88" class="code_block"><span class="p">}</span>
</div><div id="l89" class="code_block">
</div><div id="l90" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">,</span> 
</div><div id="l91" class="code_block">			  <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l92" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l93" class="code_block"><span class="p">{</span>
</div><div id="l94" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span>
</div><div id="l95" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l96" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l97" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l98" class="code_block">  <span class="p">}</span>
</div><div id="l99" class="code_block">
</div><div id="l100" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l101" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l102" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> 
</div><div id="l103" class="code_block">			       <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l104" class="code_block"><span class="p">}</span>
</div><div id="l105" class="code_block">
</div><div id="l106" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">is</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">ds</span><span class="p">,</span> 
</div><div id="l107" class="code_block">			  <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l108" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l109" class="code_block"><span class="p">{</span>
</div><div id="l110" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l111" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l112" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">,</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l113" class="code_block"><span class="p">}</span>
</div><div id="l114" class="code_block">
</div><div id="l115" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">,</span>
</div><div id="l116" class="code_block">			  <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l117" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l118" class="code_block"><span class="p">{</span>
</div><div id="l119" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span>
</div><div id="l120" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l121" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l122" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l123" class="code_block">  <span class="p">}</span>
</div><div id="l124" class="code_block">
</div><div id="l125" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l126" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l127" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> 
</div><div id="l128" class="code_block">			       <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l129" class="code_block"><span class="p">}</span>
</div><div id="l130" class="code_block">
</div><div id="l131" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">,</span> 
</div><div id="l132" class="code_block">			  <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l133" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l134" class="code_block"><span class="p">{</span>
</div><div id="l135" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span>
</div><div id="l136" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l137" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l138" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l139" class="code_block">  <span class="p">}</span>
</div><div id="l140" class="code_block">
</div><div id="l141" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l142" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l143" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> 
</div><div id="l144" class="code_block">			       <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l145" class="code_block"><span class="p">}</span>
</div><div id="l146" class="code_block">
</div><div id="l147" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">is</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">ds</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l148" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l149" class="code_block"><span class="p">{</span>
</div><div id="l150" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l151" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l152" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">,</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l153" class="code_block"><span class="p">}</span>
</div><div id="l154" class="code_block">
</div><div id="l155" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">is</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">ds</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> 
</div><div id="l156" class="code_block">			  <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l157" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l158" class="code_block"><span class="p">{</span>
</div><div id="l159" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l160" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l161" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l162" class="code_block">  <span class="p">}</span>
</div><div id="l163" class="code_block">
</div><div id="l164" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l165" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l166" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">,</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">),</span> 
</div><div id="l167" class="code_block">			       <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">b</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l168" class="code_block"><span class="p">}</span>
</div><div id="l169" class="code_block">
</div><div id="l170" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">,</span>
</div><div id="l171" class="code_block">			  <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l172" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l173" class="code_block"><span class="p">{</span>
</div><div id="l174" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span>
</div><div id="l175" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> 
</div><div id="l176" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l177" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l178" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l179" class="code_block">  <span class="p">}</span>
</div><div id="l180" class="code_block">
</div><div id="l181" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l182" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l183" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> 
</div><div id="l184" class="code_block">			       <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">),</span> 
</div><div id="l185" class="code_block">			       <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">b</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l186" class="code_block"><span class="p">}</span>
</div><div id="l187" class="code_block">
</div><div id="l188" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">,</span> <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span>
</div><div id="l189" class="code_block">			  <span class="k">const</span> <span class="n">Matrix</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l190" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l191" class="code_block"><span class="p">{</span>
</div><div id="l192" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span>
</div><div id="l193" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">is</span><span class="p">.</span><span class="n">cols</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> 
</div><div id="l194" class="code_block">      <span class="o">||</span> <span class="p">(</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">ds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l195" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l196" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l197" class="code_block">  <span class="p">}</span>
</div><div id="l198" class="code_block">
</div><div id="l199" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l200" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l201" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">is</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">ds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> 
</div><div id="l202" class="code_block">			       <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">),</span> 
</div><div id="l203" class="code_block">			       <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span><span class="n">b</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l204" class="code_block"><span class="p">}</span>
</div><div id="l205" class="code_block">
</div><div id="l206" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">)</span>
</div><div id="l207" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l208" class="code_block"><span class="p">{</span>
</div><div id="l209" class="code_block">
</div><div id="l210" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l211" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l212" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l213" class="code_block"><span class="p">}</span>
</div><div id="l214" class="code_block">
</div><div id="l215" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">)</span>
</div><div id="l216" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l217" class="code_block"><span class="p">{</span>
</div><div id="l218" class="code_block">
</div><div id="l219" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l220" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l221" class="code_block">      <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l222" class="code_block"><span class="p">}</span>
</div><div id="l223" class="code_block">
</div><div id="l224" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedRowVector</span><span class="o">&amp;</span> <span class="n">rv</span><span class="p">)</span>
</div><div id="l225" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="n">rv</span><span class="p">.</span><span class="n">length</span> <span class="p">()),</span> <span class="n">FixedPoint</span><span class="p">())</span>
</div><div id="l226" class="code_block"><span class="p">{</span>
</div><div id="l227" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rv</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l228" class="code_block">    <span class="n">elem</span> <span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">rv</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">);</span>
</div><div id="l229" class="code_block"><span class="p">}</span>
</div><div id="l230" class="code_block">
</div><div id="l231" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedColumnVector</span><span class="o">&amp;</span> <span class="n">cv</span><span class="p">)</span>
</div><div id="l232" class="code_block">  <span class="o">:</span> <span class="n">MArray</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">cv</span><span class="p">.</span><span class="n">length</span> <span class="p">(),</span> <span class="mi">1</span><span class="p">),</span> <span class="n">FixedPoint</span><span class="p">())</span>
</div><div id="l233" class="code_block"><span class="p">{</span>
</div><div id="l234" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">cv</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l235" class="code_block">    <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span> <span class="o">=</span> <span class="n">cv</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">);</span>
</div><div id="l236" class="code_block"><span class="p">}</span>
</div><div id="l237" class="code_block">
</div><div id="l238" class="code_block"><span class="cp">#define GET_FIXED_PROP(METHOD) \</span>
</div><div id="l239" class="code_block"><span class="cp">  Matrix \</span>
</div><div id="l240" class="code_block"><span class="cp">  FixedMatrix:: METHOD (void) const \</span>
</div><div id="l241" class="code_block"><span class="cp">    { \</span>
</div><div id="l242" class="code_block"><span class="cp">      int nr = rows(); \</span>
</div><div id="l243" class="code_block"><span class="cp">      int nc = cols(); \</span>
</div><div id="l244" class="code_block"><span class="cp">      Matrix retval(nr,nc); \</span>
</div><div id="l245" class="code_block"><span class="cp">      for (int i = 0; i &lt; nr; i++) \</span>
</div><div id="l246" class="code_block"><span class="cp">        for (int j = 0; j &lt; nc; j++) \</span>
</div><div id="l247" class="code_block"><span class="cp">          retval(i,j) = (double) elem(i,j) . METHOD (); \</span>
</div><div id="l248" class="code_block"><span class="cp">      return retval; \</span>
</div><div id="l249" class="code_block"><span class="cp">    } \</span>
</div><div id="l250" class="code_block">
</div><div id="l251" class="code_block"><span class="n">GET_FIXED_PROP</span><span class="p">(</span><span class="n">sign</span><span class="p">);</span>
</div><div id="l252" class="code_block"><span class="n">GET_FIXED_PROP</span><span class="p">(</span><span class="n">signbit</span><span class="p">);</span>
</div><div id="l253" class="code_block"><span class="n">GET_FIXED_PROP</span><span class="p">(</span><span class="n">getdecsize</span><span class="p">);</span>
</div><div id="l254" class="code_block"><span class="n">GET_FIXED_PROP</span><span class="p">(</span><span class="n">getintsize</span><span class="p">);</span>
</div><div id="l255" class="code_block"><span class="n">GET_FIXED_PROP</span><span class="p">(</span><span class="n">getnumber</span><span class="p">);</span>
</div><div id="l256" class="code_block"><span class="n">GET_FIXED_PROP</span><span class="p">(</span><span class="n">fixedpoint</span><span class="p">);</span>
</div><div id="l257" class="code_block">
</div><div id="l258" class="code_block"><span class="cp">#undef GET_FIXED_PROP</span>
</div><div id="l259" class="code_block">
</div><div id="l260" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l261" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">chdecsize</span> <span class="p">(</span><span class="k">const</span> <span class="kt">double</span> <span class="n">n</span><span class="p">)</span>
</div><div id="l262" class="code_block"><span class="p">{</span>
</div><div id="l263" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span><span class="p">();</span>
</div><div id="l264" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span><span class="p">();</span>
</div><div id="l265" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span><span class="n">nc</span><span class="p">));</span>
</div><div id="l266" class="code_block">
</div><div id="l267" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l268" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l269" class="code_block">      <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getintsize</span><span class="p">(),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">n</span><span class="p">,</span> <span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l270" class="code_block">
</div><div id="l271" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l272" class="code_block"><span class="p">}</span>
</div><div id="l273" class="code_block">
</div><div id="l274" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l275" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">chdecsize</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">n</span><span class="p">)</span>
</div><div id="l276" class="code_block"><span class="p">{</span>
</div><div id="l277" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span><span class="p">();</span>
</div><div id="l278" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span><span class="p">();</span>
</div><div id="l279" class="code_block">
</div><div id="l280" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">nr</span> <span class="o">!=</span> <span class="n">n</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">nc</span> <span class="o">!=</span> <span class="n">n</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l281" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch in chdecsize&quot;</span><span class="p">);</span>
</div><div id="l282" class="code_block">    <span class="k">return</span> <span class="n">FixedMatrix</span><span class="p">();</span>
</div><div id="l283" class="code_block">  <span class="p">}</span>
</div><div id="l284" class="code_block">
</div><div id="l285" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">));</span>
</div><div id="l286" class="code_block">
</div><div id="l287" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l288" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l289" class="code_block">      <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getintsize</span><span class="p">(),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">n</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l290" class="code_block">
</div><div id="l291" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l292" class="code_block"><span class="p">}</span>
</div><div id="l293" class="code_block">
</div><div id="l294" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l295" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">chintsize</span> <span class="p">(</span><span class="k">const</span> <span class="kt">double</span> <span class="n">n</span><span class="p">)</span>
</div><div id="l296" class="code_block"><span class="p">{</span>
</div><div id="l297" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span><span class="p">();</span>
</div><div id="l298" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span><span class="p">();</span>
</div><div id="l299" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">));</span>
</div><div id="l300" class="code_block">
</div><div id="l301" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l302" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l303" class="code_block">      <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">n</span><span class="p">,</span> <span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">(),</span> <span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l304" class="code_block">
</div><div id="l305" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l306" class="code_block"><span class="p">}</span>
</div><div id="l307" class="code_block">
</div><div id="l308" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l309" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">chintsize</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">n</span><span class="p">)</span>
</div><div id="l310" class="code_block"><span class="p">{</span>
</div><div id="l311" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span><span class="p">();</span>
</div><div id="l312" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span><span class="p">();</span>
</div><div id="l313" class="code_block">
</div><div id="l314" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">nr</span> <span class="o">!=</span> <span class="n">n</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">nc</span> <span class="o">!=</span> <span class="n">n</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l315" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch in chintsize&quot;</span><span class="p">);</span>
</div><div id="l316" class="code_block">    <span class="k">return</span> <span class="n">FixedMatrix</span><span class="p">();</span>
</div><div id="l317" class="code_block">  <span class="p">}</span>
</div><div id="l318" class="code_block">
</div><div id="l319" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">));</span>
</div><div id="l320" class="code_block">
</div><div id="l321" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l322" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l323" class="code_block">      <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">n</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">(),</span> <span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l324" class="code_block">
</div><div id="l325" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l326" class="code_block"><span class="p">}</span>
</div><div id="l327" class="code_block">
</div><div id="l328" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l329" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">incdecsize</span> <span class="p">(</span><span class="k">const</span> <span class="kt">double</span> <span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l330" class="code_block">  <span class="k">return</span> <span class="n">chdecsize</span><span class="p">(</span><span class="n">n</span> <span class="o">+</span> <span class="n">getdecsize</span><span class="p">());</span>
</div><div id="l331" class="code_block"><span class="p">}</span>
</div><div id="l332" class="code_block">
</div><div id="l333" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l334" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">incdecsize</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l335" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">n</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">n</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l336" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch in chintsize&quot;</span><span class="p">);</span>
</div><div id="l337" class="code_block">    <span class="k">return</span> <span class="n">FixedMatrix</span><span class="p">();</span>
</div><div id="l338" class="code_block">  <span class="p">}</span>
</div><div id="l339" class="code_block">  <span class="k">return</span> <span class="n">chdecsize</span><span class="p">(</span><span class="n">n</span> <span class="o">+</span> <span class="n">getdecsize</span><span class="p">());</span>
</div><div id="l340" class="code_block"><span class="p">}</span>
</div><div id="l341" class="code_block">
</div><div id="l342" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l343" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">incdecsize</span> <span class="p">()</span> <span class="p">{</span>
</div><div id="l344" class="code_block">  <span class="k">return</span> <span class="n">chdecsize</span><span class="p">(</span><span class="mi">1</span> <span class="o">+</span> <span class="n">getdecsize</span><span class="p">());</span>
</div><div id="l345" class="code_block"><span class="p">}</span>
</div><div id="l346" class="code_block">
</div><div id="l347" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l348" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">incintsize</span> <span class="p">(</span><span class="k">const</span> <span class="kt">double</span> <span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l349" class="code_block">  <span class="k">return</span> <span class="n">chintsize</span><span class="p">(</span><span class="n">n</span> <span class="o">+</span> <span class="n">getintsize</span><span class="p">());</span>
</div><div id="l350" class="code_block"><span class="p">}</span>
</div><div id="l351" class="code_block">
</div><div id="l352" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l353" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">incintsize</span> <span class="p">(</span><span class="k">const</span> <span class="n">Matrix</span> <span class="o">&amp;</span><span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l354" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">n</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">n</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l355" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch in chintsize&quot;</span><span class="p">);</span>
</div><div id="l356" class="code_block">    <span class="k">return</span> <span class="n">FixedMatrix</span><span class="p">();</span>
</div><div id="l357" class="code_block">  <span class="p">}</span>
</div><div id="l358" class="code_block">  <span class="k">return</span> <span class="n">chintsize</span><span class="p">(</span><span class="n">n</span> <span class="o">+</span> <span class="n">getintsize</span><span class="p">());</span>
</div><div id="l359" class="code_block"><span class="p">}</span>
</div><div id="l360" class="code_block">
</div><div id="l361" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l362" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">incintsize</span> <span class="p">()</span> <span class="p">{</span>
</div><div id="l363" class="code_block">  <span class="k">return</span> <span class="n">chintsize</span><span class="p">(</span><span class="mi">1</span> <span class="o">+</span> <span class="n">getintsize</span><span class="p">());</span>
</div><div id="l364" class="code_block"><span class="p">}</span>
</div><div id="l365" class="code_block">
</div><div id="l366" class="code_block"><span class="kt">bool</span>
</div><div id="l367" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="k">operator</span> <span class="o">==</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l368" class="code_block"><span class="p">{</span>
</div><div id="l369" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">rows</span> <span class="p">()</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">()</span> <span class="o">||</span> <span class="n">cols</span> <span class="p">()</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">())</span>
</div><div id="l370" class="code_block">    <span class="k">return</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l371" class="code_block">
</div><div id="l372" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l373" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l374" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span>
</div><div id="l375" class="code_block">	  <span class="k">return</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l376" class="code_block">    <span class="k">return</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l377" class="code_block"><span class="p">}</span>
</div><div id="l378" class="code_block">
</div><div id="l379" class="code_block"><span class="kt">bool</span>
</div><div id="l380" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="k">operator</span> <span class="o">!=</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l381" class="code_block"><span class="p">{</span>
</div><div id="l382" class="code_block">  <span class="k">return</span> <span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="k">this</span> <span class="o">==</span> <span class="n">a</span><span class="p">);</span>
</div><div id="l383" class="code_block"><span class="p">}</span>
</div><div id="l384" class="code_block">
</div><div id="l385" class="code_block"><span class="kt">bool</span>
</div><div id="l386" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">is_symmetric</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l387" class="code_block"><span class="p">{</span>
</div><div id="l388" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">is_square</span> <span class="p">()</span> <span class="o">&amp;&amp;</span> <span class="n">rows</span> <span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l389" class="code_block">    <span class="p">{</span>
</div><div id="l390" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l391" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="n">i</span><span class="o">+</span><span class="mi">1</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l392" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">!=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">j</span><span class="p">,</span> <span class="n">i</span><span class="p">))</span>
</div><div id="l393" class="code_block">	    <span class="k">return</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l394" class="code_block">
</div><div id="l395" class="code_block">      <span class="k">return</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l396" class="code_block">    <span class="p">}</span>
</div><div id="l397" class="code_block">
</div><div id="l398" class="code_block">  <span class="k">return</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l399" class="code_block"><span class="p">}</span>
</div><div id="l400" class="code_block">
</div><div id="l401" class="code_block"><span class="n">FixedMatrix</span> 
</div><div id="l402" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">concat</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">rb</span><span class="p">,</span> <span class="k">const</span> <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;&amp;</span> <span class="n">ra_idx</span><span class="p">)</span>
</div><div id="l403" class="code_block"><span class="p">{</span>
</div><div id="l404" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">rb</span><span class="p">.</span><span class="n">numel</span><span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l405" class="code_block">    <span class="n">insert</span> <span class="p">(</span><span class="n">rb</span><span class="p">,</span> <span class="n">ra_idx</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">ra_idx</span><span class="p">(</span><span class="mi">1</span><span class="p">));</span>
</div><div id="l406" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l407" class="code_block"><span class="p">}</span>
</div><div id="l408" class="code_block">
</div><div id="l409" class="code_block"><span class="n">FixedComplexMatrix</span> 
</div><div id="l410" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">concat</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedComplexMatrix</span><span class="o">&amp;</span> <span class="n">rb</span><span class="p">,</span> <span class="k">const</span> <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;&amp;</span> <span class="n">ra_idx</span><span class="p">)</span>
</div><div id="l411" class="code_block"><span class="p">{</span>
</div><div id="l412" class="code_block">  <span class="n">FixedComplexMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">);</span>
</div><div id="l413" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">rb</span><span class="p">.</span><span class="n">numel</span><span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l414" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">rb</span><span class="p">,</span> <span class="n">ra_idx</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">ra_idx</span><span class="p">(</span><span class="mi">1</span><span class="p">));</span>
</div><div id="l415" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l416" class="code_block"><span class="p">}</span>
</div><div id="l417" class="code_block">
</div><div id="l418" class="code_block"><span class="n">FixedMatrix</span><span class="o">&amp;</span>
</div><div id="l419" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">insert</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="kt">int</span> <span class="n">r</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c</span><span class="p">)</span>
</div><div id="l420" class="code_block"><span class="p">{</span>
</div><div id="l421" class="code_block">  <span class="n">Array</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="o">&gt;::</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">r</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span>
</div><div id="l422" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l423" class="code_block"><span class="p">}</span>
</div><div id="l424" class="code_block">
</div><div id="l425" class="code_block"><span class="n">FixedMatrix</span><span class="o">&amp;</span>
</div><div id="l426" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">insert</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedRowVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="kt">int</span> <span class="n">r</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c</span><span class="p">)</span>
</div><div id="l427" class="code_block"><span class="p">{</span>
</div><div id="l428" class="code_block">  <span class="kt">int</span> <span class="n">a_len</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l429" class="code_block">
</div><div id="l430" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">r</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">r</span> <span class="o">&gt;=</span> <span class="n">rows</span> <span class="p">()</span> <span class="o">||</span> <span class="n">c</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">c</span> <span class="o">+</span> <span class="n">a_len</span> <span class="o">&gt;</span> <span class="n">cols</span> <span class="p">())</span>
</div><div id="l431" class="code_block">    <span class="p">{</span>
</div><div id="l432" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;range error for insert&quot;</span><span class="p">);</span>
</div><div id="l433" class="code_block">      <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l434" class="code_block">    <span class="p">}</span>
</div><div id="l435" class="code_block">
</div><div id="l436" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">a_len</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l437" class="code_block">    <span class="p">{</span>
</div><div id="l438" class="code_block">      <span class="n">make_unique</span> <span class="p">();</span>
</div><div id="l439" class="code_block">
</div><div id="l440" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a_len</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l441" class="code_block">	<span class="n">xelem</span> <span class="p">(</span><span class="n">r</span><span class="p">,</span> <span class="n">c</span><span class="o">+</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">);</span>
</div><div id="l442" class="code_block">    <span class="p">}</span>
</div><div id="l443" class="code_block">
</div><div id="l444" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l445" class="code_block"><span class="p">}</span>
</div><div id="l446" class="code_block">
</div><div id="l447" class="code_block"><span class="n">FixedMatrix</span><span class="o">&amp;</span>
</div><div id="l448" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">insert</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedColumnVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="kt">int</span> <span class="n">r</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c</span><span class="p">)</span>
</div><div id="l449" class="code_block"><span class="p">{</span>
</div><div id="l450" class="code_block">  <span class="kt">int</span> <span class="n">a_len</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l451" class="code_block">
</div><div id="l452" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">r</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">r</span> <span class="o">+</span> <span class="n">a_len</span> <span class="o">&gt;</span> <span class="n">rows</span> <span class="p">()</span> <span class="o">||</span> <span class="n">c</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">c</span> <span class="o">&gt;=</span> <span class="n">cols</span> <span class="p">())</span>
</div><div id="l453" class="code_block">    <span class="p">{</span>
</div><div id="l454" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;range error for insert&quot;</span><span class="p">);</span>
</div><div id="l455" class="code_block">      <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l456" class="code_block">    <span class="p">}</span>
</div><div id="l457" class="code_block">
</div><div id="l458" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">a_len</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l459" class="code_block">    <span class="p">{</span>
</div><div id="l460" class="code_block">      <span class="n">make_unique</span> <span class="p">();</span>
</div><div id="l461" class="code_block">
</div><div id="l462" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a_len</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l463" class="code_block">	<span class="n">xelem</span> <span class="p">(</span><span class="n">r</span><span class="o">+</span><span class="n">i</span><span class="p">,</span> <span class="n">c</span><span class="p">)</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">);</span>
</div><div id="l464" class="code_block">    <span class="p">}</span>
</div><div id="l465" class="code_block">
</div><div id="l466" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l467" class="code_block"><span class="p">}</span>
</div><div id="l468" class="code_block">
</div><div id="l469" class="code_block"><span class="n">FixedMatrix</span><span class="o">&amp;</span>
</div><div id="l470" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">fill</span> <span class="p">(</span><span class="n">FixedPoint</span> <span class="n">val</span><span class="p">)</span>
</div><div id="l471" class="code_block"><span class="p">{</span>
</div><div id="l472" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l473" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l474" class="code_block">
</div><div id="l475" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">nc</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l476" class="code_block">    <span class="p">{</span>
</div><div id="l477" class="code_block">      <span class="n">make_unique</span> <span class="p">();</span>
</div><div id="l478" class="code_block">
</div><div id="l479" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l480" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l481" class="code_block">	  <span class="n">xelem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">val</span><span class="p">;</span>
</div><div id="l482" class="code_block">    <span class="p">}</span>
</div><div id="l483" class="code_block">
</div><div id="l484" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l485" class="code_block"><span class="p">}</span>
</div><div id="l486" class="code_block">
</div><div id="l487" class="code_block"><span class="n">FixedMatrix</span><span class="o">&amp;</span>
</div><div id="l488" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">fill</span> <span class="p">(</span><span class="n">FixedPoint</span> <span class="n">val</span><span class="p">,</span> <span class="kt">int</span> <span class="n">r1</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c1</span><span class="p">,</span> <span class="kt">int</span> <span class="n">r2</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c2</span><span class="p">)</span>
</div><div id="l489" class="code_block"><span class="p">{</span>
</div><div id="l490" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l491" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l492" class="code_block">
</div><div id="l493" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">r1</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">r2</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">c1</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">c2</span> <span class="o">&lt;</span> <span class="mi">0</span>
</div><div id="l494" class="code_block">      <span class="o">||</span> <span class="n">r1</span> <span class="o">&gt;=</span> <span class="n">nr</span> <span class="o">||</span> <span class="n">r2</span> <span class="o">&gt;=</span> <span class="n">nr</span> <span class="o">||</span> <span class="n">c1</span> <span class="o">&gt;=</span> <span class="n">nc</span> <span class="o">||</span> <span class="n">c2</span> <span class="o">&gt;=</span> <span class="n">nc</span><span class="p">)</span>
</div><div id="l495" class="code_block">    <span class="p">{</span>
</div><div id="l496" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;range error for fill&quot;</span><span class="p">);</span>
</div><div id="l497" class="code_block">      <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l498" class="code_block">    <span class="p">}</span>
</div><div id="l499" class="code_block">
</div><div id="l500" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">r1</span> <span class="o">&gt;</span> <span class="n">r2</span><span class="p">)</span> <span class="p">{</span> <span class="kt">int</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">r1</span><span class="p">;</span> <span class="n">r1</span> <span class="o">=</span> <span class="n">r2</span><span class="p">;</span> <span class="n">r2</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span> <span class="p">}</span>
</div><div id="l501" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">c1</span> <span class="o">&gt;</span> <span class="n">c2</span><span class="p">)</span> <span class="p">{</span> <span class="kt">int</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">c1</span><span class="p">;</span> <span class="n">c1</span> <span class="o">=</span> <span class="n">c2</span><span class="p">;</span> <span class="n">c2</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span> <span class="p">}</span>
</div><div id="l502" class="code_block">
</div><div id="l503" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">r2</span> <span class="o">&gt;=</span> <span class="n">r1</span> <span class="o">&amp;&amp;</span> <span class="n">c2</span> <span class="o">&gt;=</span> <span class="n">c1</span><span class="p">)</span>
</div><div id="l504" class="code_block">    <span class="p">{</span>
</div><div id="l505" class="code_block">      <span class="n">make_unique</span> <span class="p">();</span>
</div><div id="l506" class="code_block">
</div><div id="l507" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="n">c1</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;=</span> <span class="n">c2</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l508" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="n">r1</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;=</span> <span class="n">r2</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l509" class="code_block">	  <span class="n">xelem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">val</span><span class="p">;</span>
</div><div id="l510" class="code_block">    <span class="p">}</span>
</div><div id="l511" class="code_block">
</div><div id="l512" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l513" class="code_block"><span class="p">}</span>
</div><div id="l514" class="code_block">
</div><div id="l515" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l516" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">append</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l517" class="code_block"><span class="p">{</span>
</div><div id="l518" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l519" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l520" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">())</span>
</div><div id="l521" class="code_block">    <span class="p">{</span>
</div><div id="l522" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;row dimension mismatch for append&quot;</span><span class="p">);</span>
</div><div id="l523" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l524" class="code_block">    <span class="p">}</span>
</div><div id="l525" class="code_block">
</div><div id="l526" class="code_block">  <span class="kt">int</span> <span class="n">nc_insert</span> <span class="o">=</span> <span class="n">nc</span><span class="p">;</span>
</div><div id="l527" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span> <span class="o">+</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">());</span>
</div><div id="l528" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l529" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">nc_insert</span><span class="p">);</span>
</div><div id="l530" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l531" class="code_block"><span class="p">}</span>
</div><div id="l532" class="code_block">
</div><div id="l533" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l534" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">append</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedRowVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l535" class="code_block"><span class="p">{</span>
</div><div id="l536" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l537" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l538" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l539" class="code_block">    <span class="p">{</span>
</div><div id="l540" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;row dimension mismatch for append&quot;</span><span class="p">);</span>
</div><div id="l541" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l542" class="code_block">    <span class="p">}</span>
</div><div id="l543" class="code_block">
</div><div id="l544" class="code_block">  <span class="kt">int</span> <span class="n">nc_insert</span> <span class="o">=</span> <span class="n">nc</span><span class="p">;</span>
</div><div id="l545" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span> <span class="o">+</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">());</span>
</div><div id="l546" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l547" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">nc_insert</span><span class="p">);</span>
</div><div id="l548" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l549" class="code_block"><span class="p">}</span>
</div><div id="l550" class="code_block">
</div><div id="l551" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l552" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">append</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedColumnVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l553" class="code_block"><span class="p">{</span>
</div><div id="l554" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l555" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l556" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">())</span>
</div><div id="l557" class="code_block">    <span class="p">{</span>
</div><div id="l558" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;row dimension mismatch for append&quot;</span><span class="p">);</span>
</div><div id="l559" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l560" class="code_block">    <span class="p">}</span>
</div><div id="l561" class="code_block">
</div><div id="l562" class="code_block">  <span class="kt">int</span> <span class="n">nc_insert</span> <span class="o">=</span> <span class="n">nc</span><span class="p">;</span>
</div><div id="l563" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span> <span class="o">+</span> <span class="mi">1</span><span class="p">);</span>
</div><div id="l564" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l565" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">nc_insert</span><span class="p">);</span>
</div><div id="l566" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l567" class="code_block"><span class="p">}</span>
</div><div id="l568" class="code_block">
</div><div id="l569" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l570" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">stack</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l571" class="code_block"><span class="p">{</span>
</div><div id="l572" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l573" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l574" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nc</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">())</span>
</div><div id="l575" class="code_block">    <span class="p">{</span>
</div><div id="l576" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l577" class="code_block">	<span class="p">(</span><span class="s">&quot;column dimension mismatch for stack&quot;</span><span class="p">);</span>
</div><div id="l578" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l579" class="code_block">    <span class="p">}</span>
</div><div id="l580" class="code_block">
</div><div id="l581" class="code_block">  <span class="kt">int</span> <span class="n">nr_insert</span> <span class="o">=</span> <span class="n">nr</span><span class="p">;</span>
</div><div id="l582" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span> <span class="o">+</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">(),</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l583" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l584" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">nr_insert</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l585" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l586" class="code_block"><span class="p">}</span>
</div><div id="l587" class="code_block">
</div><div id="l588" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l589" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">stack</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedRowVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l590" class="code_block"><span class="p">{</span>
</div><div id="l591" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l592" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l593" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nc</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">())</span>
</div><div id="l594" class="code_block">    <span class="p">{</span>
</div><div id="l595" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l596" class="code_block">	<span class="p">(</span><span class="s">&quot;column dimension mismatch for stack&quot;</span><span class="p">);</span>
</div><div id="l597" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l598" class="code_block">    <span class="p">}</span>
</div><div id="l599" class="code_block">
</div><div id="l600" class="code_block">  <span class="kt">int</span> <span class="n">nr_insert</span> <span class="o">=</span> <span class="n">nr</span><span class="p">;</span>
</div><div id="l601" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span> <span class="o">+</span> <span class="mi">1</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l602" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l603" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">nr_insert</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l604" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l605" class="code_block"><span class="p">}</span>
</div><div id="l606" class="code_block">
</div><div id="l607" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l608" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">stack</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedColumnVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l609" class="code_block"><span class="p">{</span>
</div><div id="l610" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l611" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l612" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nc</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l613" class="code_block">    <span class="p">{</span>
</div><div id="l614" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l615" class="code_block">	<span class="p">(</span><span class="s">&quot;column dimension mismatch for stack&quot;</span><span class="p">);</span>
</div><div id="l616" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l617" class="code_block">    <span class="p">}</span>
</div><div id="l618" class="code_block">
</div><div id="l619" class="code_block">  <span class="kt">int</span> <span class="n">nr_insert</span> <span class="o">=</span> <span class="n">nr</span><span class="p">;</span>
</div><div id="l620" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span> <span class="o">+</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">(),</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l621" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l622" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">insert</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">nr_insert</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l623" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l624" class="code_block"><span class="p">}</span>
</div><div id="l625" class="code_block">
</div><div id="l626" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l627" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">extract</span> <span class="p">(</span><span class="kt">int</span> <span class="n">r1</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c1</span><span class="p">,</span> <span class="kt">int</span> <span class="n">r2</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c2</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l628" class="code_block"><span class="p">{</span>
</div><div id="l629" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">r1</span> <span class="o">&gt;</span> <span class="n">r2</span><span class="p">)</span> <span class="p">{</span> <span class="kt">int</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">r1</span><span class="p">;</span> <span class="n">r1</span> <span class="o">=</span> <span class="n">r2</span><span class="p">;</span> <span class="n">r2</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span> <span class="p">}</span>
</div><div id="l630" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">c1</span> <span class="o">&gt;</span> <span class="n">c2</span><span class="p">)</span> <span class="p">{</span> <span class="kt">int</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">c1</span><span class="p">;</span> <span class="n">c1</span> <span class="o">=</span> <span class="n">c2</span><span class="p">;</span> <span class="n">c2</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span> <span class="p">}</span>
</div><div id="l631" class="code_block">
</div><div id="l632" class="code_block">  <span class="kt">int</span> <span class="n">new_r</span> <span class="o">=</span> <span class="n">r2</span> <span class="o">-</span> <span class="n">r1</span> <span class="o">+</span> <span class="mi">1</span><span class="p">;</span>
</div><div id="l633" class="code_block">  <span class="kt">int</span> <span class="n">new_c</span> <span class="o">=</span> <span class="n">c2</span> <span class="o">-</span> <span class="n">c1</span> <span class="o">+</span> <span class="mi">1</span><span class="p">;</span>
</div><div id="l634" class="code_block">
</div><div id="l635" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">new_r</span><span class="p">,</span> <span class="n">new_c</span><span class="p">);</span>
</div><div id="l636" class="code_block">
</div><div id="l637" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">new_c</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l638" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">new_r</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l639" class="code_block">      <span class="n">result</span><span class="p">.</span><span class="n">xelem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">r1</span><span class="o">+</span><span class="n">i</span><span class="p">,</span> <span class="n">c1</span><span class="o">+</span><span class="n">j</span><span class="p">);</span>
</div><div id="l640" class="code_block">
</div><div id="l641" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l642" class="code_block"><span class="p">}</span>
</div><div id="l643" class="code_block">
</div><div id="l644" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l645" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">extract_n</span> <span class="p">(</span><span class="kt">int</span> <span class="n">r1</span><span class="p">,</span> <span class="kt">int</span> <span class="n">c1</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nr</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nc</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l646" class="code_block"><span class="p">{</span>
</div><div id="l647" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l648" class="code_block">
</div><div id="l649" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l650" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l651" class="code_block">      <span class="n">result</span><span class="p">.</span><span class="n">xelem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">r1</span><span class="o">+</span><span class="n">i</span><span class="p">,</span> <span class="n">c1</span><span class="o">+</span><span class="n">j</span><span class="p">);</span>
</div><div id="l652" class="code_block">
</div><div id="l653" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l654" class="code_block"><span class="p">}</span>
</div><div id="l655" class="code_block">
</div><div id="l656" class="code_block"><span class="c1">// extract row or column i.</span>
</div><div id="l657" class="code_block">
</div><div id="l658" class="code_block"><span class="n">FixedRowVector</span>
</div><div id="l659" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">row</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l660" class="code_block"><span class="p">{</span>
</div><div id="l661" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l662" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">i</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">i</span> <span class="o">&gt;=</span> <span class="n">rows</span> <span class="p">())</span>
</div><div id="l663" class="code_block">    <span class="p">{</span>
</div><div id="l664" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;invalid row selection&quot;</span><span class="p">);</span>
</div><div id="l665" class="code_block">      <span class="k">return</span> <span class="n">FixedRowVector</span> <span class="p">();</span>
</div><div id="l666" class="code_block">    <span class="p">}</span>
</div><div id="l667" class="code_block">
</div><div id="l668" class="code_block">  <span class="n">FixedRowVector</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nc</span><span class="p">);</span>
</div><div id="l669" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l670" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">xelem</span> <span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l671" class="code_block">
</div><div id="l672" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l673" class="code_block"><span class="p">}</span>
</div><div id="l674" class="code_block">
</div><div id="l675" class="code_block"><span class="n">FixedRowVector</span>
</div><div id="l676" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">row</span> <span class="p">(</span><span class="kt">char</span> <span class="o">*</span><span class="n">s</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l677" class="code_block"><span class="p">{</span>
</div><div id="l678" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="o">!</span> <span class="n">s</span><span class="p">)</span>
</div><div id="l679" class="code_block">    <span class="p">{</span>
</div><div id="l680" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;invalid row selection&quot;</span><span class="p">);</span>
</div><div id="l681" class="code_block">      <span class="k">return</span> <span class="n">FixedRowVector</span> <span class="p">();</span>
</div><div id="l682" class="code_block">    <span class="p">}</span>
</div><div id="l683" class="code_block">
</div><div id="l684" class="code_block">  <span class="kt">char</span> <span class="n">c</span> <span class="o">=</span> <span class="o">*</span><span class="n">s</span><span class="p">;</span>
</div><div id="l685" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;f&#39;</span> <span class="o">||</span> <span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;F&#39;</span><span class="p">)</span>
</div><div id="l686" class="code_block">    <span class="k">return</span> <span class="n">row</span> <span class="p">(</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l687" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;l&#39;</span> <span class="o">||</span> <span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;L&#39;</span><span class="p">)</span>
</div><div id="l688" class="code_block">    <span class="k">return</span> <span class="n">row</span> <span class="p">(</span><span class="n">rows</span> <span class="p">()</span> <span class="o">-</span> <span class="mi">1</span><span class="p">);</span>
</div><div id="l689" class="code_block">  <span class="k">else</span>
</div><div id="l690" class="code_block">    <span class="p">{</span>
</div><div id="l691" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;invalid row selection&quot;</span><span class="p">);</span>
</div><div id="l692" class="code_block">      <span class="k">return</span> <span class="n">FixedRowVector</span> <span class="p">();</span>
</div><div id="l693" class="code_block">    <span class="p">}</span>
</div><div id="l694" class="code_block"><span class="p">}</span>
</div><div id="l695" class="code_block">
</div><div id="l696" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l697" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">column</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l698" class="code_block"><span class="p">{</span>
</div><div id="l699" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l700" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">i</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">i</span> <span class="o">&gt;=</span> <span class="n">cols</span> <span class="p">())</span>
</div><div id="l701" class="code_block">    <span class="p">{</span>
</div><div id="l702" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;invalid column selection&quot;</span><span class="p">);</span>
</div><div id="l703" class="code_block">      <span class="k">return</span> <span class="n">FixedColumnVector</span> <span class="p">();</span>
</div><div id="l704" class="code_block">    <span class="p">}</span>
</div><div id="l705" class="code_block">
</div><div id="l706" class="code_block">  <span class="n">FixedColumnVector</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span><span class="p">);</span>
</div><div id="l707" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l708" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">xelem</span> <span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">j</span><span class="p">,</span> <span class="n">i</span><span class="p">);</span>
</div><div id="l709" class="code_block">
</div><div id="l710" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l711" class="code_block"><span class="p">}</span>
</div><div id="l712" class="code_block">
</div><div id="l713" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l714" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">column</span> <span class="p">(</span><span class="kt">char</span> <span class="o">*</span><span class="n">s</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l715" class="code_block"><span class="p">{</span>
</div><div id="l716" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="o">!</span> <span class="n">s</span><span class="p">)</span>
</div><div id="l717" class="code_block">    <span class="p">{</span>
</div><div id="l718" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;invalid column selection&quot;</span><span class="p">);</span>
</div><div id="l719" class="code_block">      <span class="k">return</span> <span class="n">FixedColumnVector</span> <span class="p">();</span>
</div><div id="l720" class="code_block">    <span class="p">}</span>
</div><div id="l721" class="code_block">
</div><div id="l722" class="code_block">  <span class="kt">char</span> <span class="n">c</span> <span class="o">=</span> <span class="o">*</span><span class="n">s</span><span class="p">;</span>
</div><div id="l723" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;f&#39;</span> <span class="o">||</span> <span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;F&#39;</span><span class="p">)</span>
</div><div id="l724" class="code_block">    <span class="k">return</span> <span class="n">column</span> <span class="p">(</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l725" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;l&#39;</span> <span class="o">||</span> <span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;L&#39;</span><span class="p">)</span>
</div><div id="l726" class="code_block">    <span class="k">return</span> <span class="n">column</span> <span class="p">(</span><span class="n">cols</span> <span class="p">()</span> <span class="o">-</span> <span class="mi">1</span><span class="p">);</span>
</div><div id="l727" class="code_block">  <span class="k">else</span>
</div><div id="l728" class="code_block">    <span class="p">{</span>
</div><div id="l729" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;invalid column selection&quot;</span><span class="p">);</span>
</div><div id="l730" class="code_block">      <span class="k">return</span> <span class="n">FixedColumnVector</span> <span class="p">();</span>
</div><div id="l731" class="code_block">    <span class="p">}</span>
</div><div id="l732" class="code_block"><span class="p">}</span>
</div><div id="l733" class="code_block">
</div><div id="l734" class="code_block"><span class="c1">// unary operations</span>
</div><div id="l735" class="code_block">
</div><div id="l736" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l737" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="k">operator</span> <span class="o">!</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l738" class="code_block"><span class="p">{</span>
</div><div id="l739" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l740" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l741" class="code_block">
</div><div id="l742" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">b</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l743" class="code_block">
</div><div id="l744" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l745" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l746" class="code_block">      <span class="n">b</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span>  <span class="o">!</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="p">;</span>
</div><div id="l747" class="code_block">
</div><div id="l748" class="code_block">  <span class="k">return</span> <span class="n">b</span><span class="p">;</span>
</div><div id="l749" class="code_block"><span class="p">}</span>
</div><div id="l750" class="code_block">
</div><div id="l751" class="code_block"><span class="c1">// column vector by row vector -&gt; matrix operations</span>
</div><div id="l752" class="code_block">
</div><div id="l753" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l754" class="code_block"><span class="k">operator</span> <span class="o">*</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedColumnVector</span><span class="o">&amp;</span> <span class="n">v</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedRowVector</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l755" class="code_block"><span class="p">{</span>
</div><div id="l756" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l757" class="code_block">
</div><div id="l758" class="code_block">  <span class="kt">int</span> <span class="n">len</span> <span class="o">=</span> <span class="n">v</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l759" class="code_block">
</div><div id="l760" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">len</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l761" class="code_block">    <span class="p">{</span>
</div><div id="l762" class="code_block">      <span class="kt">int</span> <span class="n">a_len</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l763" class="code_block">
</div><div id="l764" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">len</span><span class="p">,</span> <span class="n">a_len</span><span class="p">);</span>
</div><div id="l765" class="code_block">
</div><div id="l766" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">len</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l767" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a_len</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l768" class="code_block">	  <span class="n">retval</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">v</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">*</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">j</span><span class="p">);</span>
</div><div id="l769" class="code_block">    <span class="p">}</span>
</div><div id="l770" class="code_block">
</div><div id="l771" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l772" class="code_block"><span class="p">}</span>
</div><div id="l773" class="code_block">
</div><div id="l774" class="code_block"><span class="c1">// other operations.</span>
</div><div id="l775" class="code_block">
</div><div id="l776" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l777" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">map</span> <span class="p">(</span><span class="n">fp_fp_Mapper</span> <span class="n">f</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l778" class="code_block"><span class="p">{</span>
</div><div id="l779" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">b</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">);</span>
</div><div id="l780" class="code_block">  <span class="k">return</span> <span class="n">b</span><span class="p">.</span><span class="n">apply</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l781" class="code_block"><span class="p">}</span>
</div><div id="l782" class="code_block">
</div><div id="l783" class="code_block"><span class="n">FixedMatrix</span><span class="o">&amp;</span>
</div><div id="l784" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">apply</span> <span class="p">(</span><span class="n">fp_fp_Mapper</span> <span class="n">f</span><span class="p">)</span>
</div><div id="l785" class="code_block"><span class="p">{</span>
</div><div id="l786" class="code_block">  <span class="n">FixedPoint</span> <span class="o">*</span><span class="n">d</span> <span class="o">=</span> <span class="n">fortran_vec</span> <span class="p">();</span> <span class="c1">// Ensures only one reference to my privates!</span>
</div><div id="l787" class="code_block">
</div><div id="l788" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">length</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l789" class="code_block">    <span class="n">d</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">f</span> <span class="p">(</span><span class="n">d</span><span class="p">[</span><span class="n">i</span><span class="p">]);</span>
</div><div id="l790" class="code_block">
</div><div id="l791" class="code_block">  <span class="k">return</span> <span class="o">*</span><span class="k">this</span><span class="p">;</span>
</div><div id="l792" class="code_block"><span class="p">}</span>
</div><div id="l793" class="code_block">
</div><div id="l794" class="code_block"><span class="n">boolMatrix</span>
</div><div id="l795" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">all</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l796" class="code_block"><span class="p">{</span>
</div><div id="l797" class="code_block">  <span class="k">return</span> <span class="n">do_mx_red_op</span><span class="o">&lt;</span><span class="kt">bool</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_all</span><span class="p">);</span>
</div><div id="l798" class="code_block"><span class="p">}</span>
</div><div id="l799" class="code_block">
</div><div id="l800" class="code_block"><span class="n">boolMatrix</span>
</div><div id="l801" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">any</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l802" class="code_block"><span class="p">{</span>
</div><div id="l803" class="code_block">  <span class="k">return</span> <span class="n">do_mx_red_op</span><span class="o">&lt;</span><span class="kt">bool</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_any</span><span class="p">);</span>
</div><div id="l804" class="code_block"><span class="p">}</span>
</div><div id="l805" class="code_block">
</div><div id="l806" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l807" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">cumprod</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l808" class="code_block"><span class="p">{</span>
</div><div id="l809" class="code_block">  <span class="k">return</span> <span class="n">do_mx_cum_op</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_cumprod</span><span class="p">);</span>
</div><div id="l810" class="code_block"><span class="p">}</span>
</div><div id="l811" class="code_block">
</div><div id="l812" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l813" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">cumsum</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l814" class="code_block"><span class="p">{</span>
</div><div id="l815" class="code_block">  <span class="k">return</span> <span class="n">do_mx_cum_op</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_cumsum</span><span class="p">);</span>
</div><div id="l816" class="code_block"><span class="p">}</span>
</div><div id="l817" class="code_block">
</div><div id="l818" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l819" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">prod</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l820" class="code_block"><span class="p">{</span>
</div><div id="l821" class="code_block">  <span class="k">return</span> <span class="n">do_mx_red_op</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_prod</span><span class="p">);</span>
</div><div id="l822" class="code_block"><span class="p">}</span>
</div><div id="l823" class="code_block">
</div><div id="l824" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l825" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">sum</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l826" class="code_block"><span class="p">{</span>
</div><div id="l827" class="code_block">  <span class="k">return</span> <span class="n">do_mx_red_op</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_sum</span><span class="p">);</span>
</div><div id="l828" class="code_block"><span class="p">}</span>
</div><div id="l829" class="code_block">
</div><div id="l830" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l831" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">sumsq</span> <span class="p">(</span><span class="kt">int</span> <span class="n">dim</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l832" class="code_block"><span class="p">{</span>
</div><div id="l833" class="code_block">  <span class="k">return</span> <span class="n">do_mx_red_op</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="o">&gt;</span> <span class="p">(</span><span class="o">*</span><span class="k">this</span><span class="p">,</span> <span class="n">dim</span><span class="p">,</span> <span class="n">mx_inline_sumsq</span><span class="p">);</span>
</div><div id="l834" class="code_block"><span class="p">}</span>
</div><div id="l835" class="code_block">
</div><div id="l836" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l837" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">abs</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l838" class="code_block"><span class="p">{</span>
</div><div id="l839" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l840" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l841" class="code_block">
</div><div id="l842" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l843" class="code_block">
</div><div id="l844" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l845" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l846" class="code_block">      <span class="n">retval</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">));</span>
</div><div id="l847" class="code_block">
</div><div id="l848" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l849" class="code_block"><span class="p">}</span>
</div><div id="l850" class="code_block">
</div><div id="l851" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l852" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">diag</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l853" class="code_block"><span class="p">{</span>
</div><div id="l854" class="code_block">  <span class="k">return</span> <span class="n">diag</span> <span class="p">(</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l855" class="code_block"><span class="p">}</span>
</div><div id="l856" class="code_block">
</div><div id="l857" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l858" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">diag</span> <span class="p">(</span><span class="kt">int</span> <span class="n">k</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l859" class="code_block"><span class="p">{</span>
</div><div id="l860" class="code_block">  <span class="kt">int</span> <span class="n">nnr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l861" class="code_block">  <span class="kt">int</span> <span class="n">nnc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l862" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l863" class="code_block">    <span class="n">nnc</span> <span class="o">-=</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l864" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l865" class="code_block">    <span class="n">nnr</span> <span class="o">+=</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l866" class="code_block">
</div><div id="l867" class="code_block">  <span class="n">FixedColumnVector</span> <span class="n">d</span><span class="p">;</span>
</div><div id="l868" class="code_block">
</div><div id="l869" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nnr</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">nnc</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l870" class="code_block">    <span class="p">{</span>
</div><div id="l871" class="code_block">      <span class="kt">int</span> <span class="n">ndiag</span> <span class="o">=</span> <span class="p">(</span><span class="n">nnr</span> <span class="o">&lt;</span> <span class="n">nnc</span><span class="p">)</span> <span class="o">?</span> <span class="n">nnr</span> <span class="o">:</span> <span class="n">nnc</span><span class="p">;</span>
</div><div id="l872" class="code_block">
</div><div id="l873" class="code_block">      <span class="n">d</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">ndiag</span><span class="p">);</span>
</div><div id="l874" class="code_block">
</div><div id="l875" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l876" class="code_block">	<span class="p">{</span>
</div><div id="l877" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">ndiag</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l878" class="code_block">	    <span class="n">d</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">i</span><span class="o">+</span><span class="n">k</span><span class="p">);</span>
</div><div id="l879" class="code_block">	<span class="p">}</span>
</div><div id="l880" class="code_block">      <span class="k">else</span> <span class="k">if</span> <span class="p">(</span> <span class="n">k</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l881" class="code_block">	<span class="p">{</span>
</div><div id="l882" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">ndiag</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l883" class="code_block">	    <span class="n">d</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="o">-</span><span class="n">k</span><span class="p">,</span> <span class="n">i</span><span class="p">);</span>
</div><div id="l884" class="code_block">	<span class="p">}</span>
</div><div id="l885" class="code_block">      <span class="k">else</span>
</div><div id="l886" class="code_block">	<span class="p">{</span>
</div><div id="l887" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">ndiag</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l888" class="code_block">	    <span class="n">d</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">i</span><span class="p">);</span>
</div><div id="l889" class="code_block">	<span class="p">}</span>
</div><div id="l890" class="code_block">    <span class="p">}</span>
</div><div id="l891" class="code_block">  <span class="k">else</span>
</div><div id="l892" class="code_block">    <span class="n">std</span><span class="o">::</span><span class="n">cerr</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;diag: requested diagonal out of range</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">;</span>
</div><div id="l893" class="code_block">
</div><div id="l894" class="code_block">  <span class="k">return</span> <span class="n">d</span><span class="p">;</span>
</div><div id="l895" class="code_block"><span class="p">}</span>
</div><div id="l896" class="code_block">
</div><div id="l897" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l898" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">row_min</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l899" class="code_block"><span class="p">{</span>
</div><div id="l900" class="code_block">  <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">index</span><span class="p">;</span>
</div><div id="l901" class="code_block">  <span class="k">return</span> <span class="n">row_min</span> <span class="p">(</span><span class="n">index</span><span class="p">);</span>
</div><div id="l902" class="code_block"><span class="p">}</span>
</div><div id="l903" class="code_block">
</div><div id="l904" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l905" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">row_min</span> <span class="p">(</span><span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;&amp;</span> <span class="n">index</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l906" class="code_block"><span class="p">{</span>
</div><div id="l907" class="code_block">  <span class="n">FixedColumnVector</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l908" class="code_block">
</div><div id="l909" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l910" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l911" class="code_block">
</div><div id="l912" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">nc</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l913" class="code_block">    <span class="p">{</span>
</div><div id="l914" class="code_block">      <span class="n">result</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">nr</span><span class="p">);</span>
</div><div id="l915" class="code_block">      <span class="n">index</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="mi">1</span><span class="p">));</span>
</div><div id="l916" class="code_block">
</div><div id="l917" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l918" class="code_block">        <span class="p">{</span>
</div><div id="l919" class="code_block">	  <span class="kt">int</span> <span class="n">idx_j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l920" class="code_block">
</div><div id="l921" class="code_block">	  <span class="n">FixedPoint</span> <span class="n">tmp_min</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">idx_j</span><span class="p">);</span>
</div><div id="l922" class="code_block">
</div><div id="l923" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l924" class="code_block">	    <span class="p">{</span>
</div><div id="l925" class="code_block">	      <span class="n">FixedPoint</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l926" class="code_block">	      <span class="k">if</span> <span class="p">(</span><span class="n">tmp</span> <span class="o">&lt;</span> <span class="n">tmp_min</span><span class="p">)</span>
</div><div id="l927" class="code_block">		<span class="p">{</span>
</div><div id="l928" class="code_block">		  <span class="n">idx_j</span> <span class="o">=</span> <span class="n">j</span><span class="p">;</span>
</div><div id="l929" class="code_block">		  <span class="n">tmp_min</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l930" class="code_block">		<span class="p">}</span>
</div><div id="l931" class="code_block">	    <span class="p">}</span>
</div><div id="l932" class="code_block">	  
</div><div id="l933" class="code_block">	  <span class="n">result</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp_min</span><span class="p">;</span>
</div><div id="l934" class="code_block">	  <span class="n">index</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">idx_j</span><span class="p">;</span>
</div><div id="l935" class="code_block">        <span class="p">}</span>
</div><div id="l936" class="code_block">    <span class="p">}</span>
</div><div id="l937" class="code_block">  
</div><div id="l938" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l939" class="code_block"><span class="p">}</span>
</div><div id="l940" class="code_block">
</div><div id="l941" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l942" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">row_max</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l943" class="code_block"><span class="p">{</span>
</div><div id="l944" class="code_block">  <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">index</span><span class="p">;</span>
</div><div id="l945" class="code_block">  <span class="k">return</span> <span class="n">row_max</span> <span class="p">(</span><span class="n">index</span><span class="p">);</span>
</div><div id="l946" class="code_block"><span class="p">}</span>
</div><div id="l947" class="code_block">
</div><div id="l948" class="code_block"><span class="n">FixedColumnVector</span>
</div><div id="l949" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">row_max</span> <span class="p">(</span><span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;&amp;</span> <span class="n">index</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l950" class="code_block"><span class="p">{</span>
</div><div id="l951" class="code_block">  <span class="n">FixedColumnVector</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l952" class="code_block">
</div><div id="l953" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l954" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l955" class="code_block">
</div><div id="l956" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">nc</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l957" class="code_block">    <span class="p">{</span>
</div><div id="l958" class="code_block">      <span class="n">result</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">nr</span><span class="p">);</span>
</div><div id="l959" class="code_block">      <span class="n">index</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="mi">1</span><span class="p">));</span>
</div><div id="l960" class="code_block">
</div><div id="l961" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l962" class="code_block">        <span class="p">{</span>
</div><div id="l963" class="code_block">	  <span class="kt">int</span> <span class="n">idx_j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l964" class="code_block">
</div><div id="l965" class="code_block">	  <span class="n">FixedPoint</span> <span class="n">tmp_max</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">idx_j</span><span class="p">);</span>
</div><div id="l966" class="code_block">
</div><div id="l967" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l968" class="code_block">	    <span class="p">{</span>
</div><div id="l969" class="code_block">	      <span class="n">FixedPoint</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l970" class="code_block">	      <span class="k">if</span> <span class="p">(</span><span class="n">tmp</span> <span class="o">&gt;</span> <span class="n">tmp_max</span><span class="p">)</span>
</div><div id="l971" class="code_block">		<span class="p">{</span>
</div><div id="l972" class="code_block">		  <span class="n">idx_j</span> <span class="o">=</span> <span class="n">j</span><span class="p">;</span>
</div><div id="l973" class="code_block">		  <span class="n">tmp_max</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l974" class="code_block">		<span class="p">}</span>
</div><div id="l975" class="code_block">	    <span class="p">}</span>
</div><div id="l976" class="code_block">
</div><div id="l977" class="code_block">	  <span class="n">result</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp_max</span><span class="p">;</span>
</div><div id="l978" class="code_block">	  <span class="n">index</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">idx_j</span><span class="p">;</span>
</div><div id="l979" class="code_block">        <span class="p">}</span>
</div><div id="l980" class="code_block">    <span class="p">}</span>
</div><div id="l981" class="code_block">
</div><div id="l982" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l983" class="code_block"><span class="p">}</span>
</div><div id="l984" class="code_block">
</div><div id="l985" class="code_block"><span class="n">FixedRowVector</span>
</div><div id="l986" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">column_min</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l987" class="code_block"><span class="p">{</span>
</div><div id="l988" class="code_block">  <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">index</span><span class="p">;</span>
</div><div id="l989" class="code_block">  <span class="k">return</span> <span class="n">column_min</span> <span class="p">(</span><span class="n">index</span><span class="p">);</span>
</div><div id="l990" class="code_block"><span class="p">}</span>
</div><div id="l991" class="code_block">
</div><div id="l992" class="code_block"><span class="n">FixedRowVector</span>
</div><div id="l993" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">column_min</span> <span class="p">(</span><span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;&amp;</span> <span class="n">index</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l994" class="code_block"><span class="p">{</span>
</div><div id="l995" class="code_block">  <span class="n">FixedRowVector</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l996" class="code_block">
</div><div id="l997" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l998" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l999" class="code_block">
</div><div id="l1000" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">nc</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l1001" class="code_block">    <span class="p">{</span>
</div><div id="l1002" class="code_block">      <span class="n">result</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">nc</span><span class="p">);</span>
</div><div id="l1003" class="code_block">      <span class="n">index</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="n">nc</span><span class="p">));</span>
</div><div id="l1004" class="code_block">
</div><div id="l1005" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1006" class="code_block">        <span class="p">{</span>
</div><div id="l1007" class="code_block">	  <span class="kt">int</span> <span class="n">idx_i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l1008" class="code_block">
</div><div id="l1009" class="code_block">	  <span class="n">FixedPoint</span> <span class="n">tmp_min</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">idx_i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l1010" class="code_block">
</div><div id="l1011" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1012" class="code_block">	    <span class="p">{</span>
</div><div id="l1013" class="code_block">	      <span class="n">FixedPoint</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l1014" class="code_block">	      <span class="k">if</span> <span class="p">(</span><span class="n">tmp</span> <span class="o">&lt;</span> <span class="n">tmp_min</span><span class="p">)</span>
</div><div id="l1015" class="code_block">		<span class="p">{</span>
</div><div id="l1016" class="code_block">		  <span class="n">idx_i</span> <span class="o">=</span> <span class="n">i</span><span class="p">;</span>
</div><div id="l1017" class="code_block">		  <span class="n">tmp_min</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l1018" class="code_block">		<span class="p">}</span>
</div><div id="l1019" class="code_block">	    <span class="p">}</span>
</div><div id="l1020" class="code_block">
</div><div id="l1021" class="code_block">	  <span class="n">result</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp_min</span><span class="p">;</span>
</div><div id="l1022" class="code_block">	  <span class="n">index</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">idx_i</span><span class="p">;</span>
</div><div id="l1023" class="code_block">        <span class="p">}</span>
</div><div id="l1024" class="code_block">    <span class="p">}</span>
</div><div id="l1025" class="code_block">
</div><div id="l1026" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1027" class="code_block"><span class="p">}</span>
</div><div id="l1028" class="code_block">
</div><div id="l1029" class="code_block"><span class="n">FixedRowVector</span>
</div><div id="l1030" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">column_max</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l1031" class="code_block"><span class="p">{</span>
</div><div id="l1032" class="code_block">  <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">index</span><span class="p">;</span>
</div><div id="l1033" class="code_block">  <span class="k">return</span> <span class="n">column_max</span> <span class="p">(</span><span class="n">index</span><span class="p">);</span>
</div><div id="l1034" class="code_block"><span class="p">}</span>
</div><div id="l1035" class="code_block">
</div><div id="l1036" class="code_block"><span class="n">FixedRowVector</span>
</div><div id="l1037" class="code_block"><span class="n">FixedMatrix</span><span class="o">::</span><span class="n">column_max</span> <span class="p">(</span><span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;&amp;</span> <span class="n">index</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l1038" class="code_block"><span class="p">{</span>
</div><div id="l1039" class="code_block">  <span class="n">FixedRowVector</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1040" class="code_block">
</div><div id="l1041" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l1042" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">cols</span> <span class="p">();</span>
</div><div id="l1043" class="code_block">
</div><div id="l1044" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">nc</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l1045" class="code_block">    <span class="p">{</span>
</div><div id="l1046" class="code_block">      <span class="n">result</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">nc</span><span class="p">);</span>
</div><div id="l1047" class="code_block">      <span class="n">index</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="n">nc</span><span class="p">));</span>
</div><div id="l1048" class="code_block">
</div><div id="l1049" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1050" class="code_block">        <span class="p">{</span>
</div><div id="l1051" class="code_block">	  <span class="kt">int</span> <span class="n">idx_i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l1052" class="code_block">
</div><div id="l1053" class="code_block">	  <span class="n">FixedPoint</span> <span class="n">tmp_max</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">idx_i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l1054" class="code_block">
</div><div id="l1055" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1056" class="code_block">	    <span class="p">{</span>
</div><div id="l1057" class="code_block">	      <span class="n">FixedPoint</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">);</span>
</div><div id="l1058" class="code_block">
</div><div id="l1059" class="code_block">	      <span class="k">if</span> <span class="p">(</span><span class="n">tmp</span> <span class="o">&gt;</span> <span class="n">tmp_max</span><span class="p">)</span>
</div><div id="l1060" class="code_block">		<span class="p">{</span>
</div><div id="l1061" class="code_block">		  <span class="n">idx_i</span> <span class="o">=</span> <span class="n">i</span><span class="p">;</span>
</div><div id="l1062" class="code_block">		  <span class="n">tmp_max</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l1063" class="code_block">		<span class="p">}</span>
</div><div id="l1064" class="code_block">	    <span class="p">}</span>
</div><div id="l1065" class="code_block">
</div><div id="l1066" class="code_block">	  <span class="n">result</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp_max</span><span class="p">;</span>
</div><div id="l1067" class="code_block">	  <span class="n">index</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">idx_i</span><span class="p">;</span>
</div><div id="l1068" class="code_block">        <span class="p">}</span>
</div><div id="l1069" class="code_block">    <span class="p">}</span>
</div><div id="l1070" class="code_block">
</div><div id="l1071" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1072" class="code_block"><span class="p">}</span>
</div><div id="l1073" class="code_block">
</div><div id="l1074" class="code_block"><span class="cp">#define DO_FIXED_MAT_FUNC(FUNC) \</span>
</div><div id="l1075" class="code_block"><span class="cp">  FixedMatrix FUNC (const FixedMatrix&amp; x) \</span>
</div><div id="l1076" class="code_block"><span class="cp">  {  \</span>
</div><div id="l1077" class="code_block"><span class="cp">    FixedMatrix retval ( x.rows(), x.cols()); \</span>
</div><div id="l1078" class="code_block"><span class="cp">    for (int j = 0; j &lt; x.cols(); j++) \</span>
</div><div id="l1079" class="code_block"><span class="cp">      for (int i = 0; i &lt; x.rows(); i++) \</span>
</div><div id="l1080" class="code_block"><span class="cp">        retval(i,j) = FUNC ( x (i,j) ); \</span>
</div><div id="l1081" class="code_block"><span class="cp">    return retval; \</span>
</div><div id="l1082" class="code_block"><span class="cp">  }</span>
</div><div id="l1083" class="code_block">
</div><div id="l1084" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">real</span><span class="p">);</span>
</div><div id="l1085" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">imag</span><span class="p">);</span>
</div><div id="l1086" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">conj</span><span class="p">);</span>
</div><div id="l1087" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">abs</span><span class="p">);</span>
</div><div id="l1088" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">cos</span><span class="p">);</span>
</div><div id="l1089" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">cosh</span><span class="p">);</span>
</div><div id="l1090" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">sin</span><span class="p">);</span>
</div><div id="l1091" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">sinh</span><span class="p">);</span>
</div><div id="l1092" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">tan</span><span class="p">);</span>
</div><div id="l1093" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">tanh</span><span class="p">);</span>
</div><div id="l1094" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">sqrt</span><span class="p">);</span>
</div><div id="l1095" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">exp</span><span class="p">);</span>
</div><div id="l1096" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">log</span><span class="p">);</span>
</div><div id="l1097" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">log10</span><span class="p">);</span>
</div><div id="l1098" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">round</span><span class="p">);</span>
</div><div id="l1099" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">rint</span><span class="p">);</span>
</div><div id="l1100" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">floor</span><span class="p">);</span>
</div><div id="l1101" class="code_block"><span class="n">DO_FIXED_MAT_FUNC</span><span class="p">(</span><span class="n">ceil</span><span class="p">);</span>
</div><div id="l1102" class="code_block">
</div><div id="l1103" class="code_block"><span class="n">FixedMatrix</span> <span class="n">elem_pow</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">b</span><span class="p">)</span>
</div><div id="l1104" class="code_block"><span class="p">{</span>
</div><div id="l1105" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1106" class="code_block">  <span class="kt">int</span> <span class="n">a_nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1107" class="code_block">  <span class="kt">int</span> <span class="n">a_nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span>
</div><div id="l1108" class="code_block">  <span class="kt">int</span> <span class="n">b_nr</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1109" class="code_block">  <span class="kt">int</span> <span class="n">b_nc</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span>
</div><div id="l1110" class="code_block">
</div><div id="l1111" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">a_nr</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">&amp;&amp;</span> <span class="n">a_nc</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l1112" class="code_block">    <span class="p">{</span>
</div><div id="l1113" class="code_block">      <span class="n">retval</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">b_nr</span><span class="p">,</span><span class="n">b_nc</span><span class="p">);</span>
</div><div id="l1114" class="code_block">      <span class="n">FixedPoint</span> <span class="n">ad</span> <span class="o">=</span> <span class="n">a</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l1115" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">b_nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1116" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">b_nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1117" class="code_block">	  <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">pow</span><span class="p">(</span><span class="n">ad</span><span class="p">,</span> <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l1118" class="code_block">    <span class="p">}</span>
</div><div id="l1119" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">b_nr</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">&amp;&amp;</span> <span class="n">b_nc</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l1120" class="code_block">    <span class="p">{</span>
</div><div id="l1121" class="code_block">      <span class="n">retval</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">a_nr</span><span class="p">,</span><span class="n">a_nc</span><span class="p">);</span>
</div><div id="l1122" class="code_block">      <span class="n">FixedPoint</span> <span class="n">bd</span> <span class="o">=</span> <span class="n">b</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l1123" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a_nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1124" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a_nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1125" class="code_block">	  <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">pow</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="n">bd</span><span class="p">);</span>
</div><div id="l1126" class="code_block">    <span class="p">}</span>
</div><div id="l1127" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">((</span><span class="n">a_nr</span> <span class="o">==</span> <span class="n">b_nr</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">a_nc</span> <span class="o">==</span> <span class="n">b_nc</span><span class="p">))</span>
</div><div id="l1128" class="code_block">    <span class="p">{</span>
</div><div id="l1129" class="code_block">      <span class="n">retval</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">a_nr</span><span class="p">,</span><span class="n">a_nc</span><span class="p">);</span>
</div><div id="l1130" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a_nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1131" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a_nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1132" class="code_block">	  <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">pow</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l1133" class="code_block">    <span class="p">}</span>
</div><div id="l1134" class="code_block">  <span class="k">else</span>
</div><div id="l1135" class="code_block">    <span class="n">gripe_nonconformant</span> <span class="p">(</span><span class="s">&quot;operator .^&quot;</span><span class="p">,</span> <span class="n">a_nr</span><span class="p">,</span> <span class="n">a_nc</span><span class="p">,</span> <span class="n">a_nr</span><span class="p">,</span> <span class="n">a_nc</span><span class="p">);</span>
</div><div id="l1136" class="code_block">
</div><div id="l1137" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1138" class="code_block"><span class="p">}</span>
</div><div id="l1139" class="code_block">
</div><div id="l1140" class="code_block"><span class="n">FixedMatrix</span> <span class="n">elem_pow</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedPoint</span> <span class="o">&amp;</span><span class="n">b</span><span class="p">)</span>
</div><div id="l1141" class="code_block"><span class="p">{</span>
</div><div id="l1142" class="code_block">  <span class="k">return</span> <span class="n">elem_pow</span> <span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">FixedMatrix</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">b</span><span class="p">));</span>
</div><div id="l1143" class="code_block"><span class="p">}</span>
</div><div id="l1144" class="code_block">
</div><div id="l1145" class="code_block"><span class="n">FixedMatrix</span> <span class="n">elem_pow</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedPoint</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">b</span><span class="p">)</span>
</div><div id="l1146" class="code_block"><span class="p">{</span>
</div><div id="l1147" class="code_block">  <span class="k">return</span> <span class="n">elem_pow</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">a</span><span class="p">),</span> <span class="n">b</span><span class="p">);</span>
</div><div id="l1148" class="code_block"><span class="p">}</span>
</div><div id="l1149" class="code_block">
</div><div id="l1150" class="code_block"><span class="n">FixedMatrix</span> <span class="n">pow</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="kt">int</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l1151" class="code_block"><span class="p">{</span>
</div><div id="l1152" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1153" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1154" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span>
</div><div id="l1155" class="code_block">
</div><div id="l1156" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">nr</span> <span class="o">!=</span> <span class="n">nc</span><span class="p">)</span>
</div><div id="l1157" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l1158" class="code_block">      <span class="p">(</span><span class="s">&quot;for A^x, A must be square and x scalar&quot;</span><span class="p">);</span>
</div><div id="l1159" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">b</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span> 
</div><div id="l1160" class="code_block">    <span class="p">{</span>
</div><div id="l1161" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="n">a</span><span class="p">;</span>
</div><div id="l1162" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1163" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1164" class="code_block">	  <span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span>
</div><div id="l1165" class="code_block">            <span class="n">FixedPoint</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getintsize</span><span class="p">(),</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">(),</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l1166" class="code_block">    <span class="p">}</span>
</div><div id="l1167" class="code_block">  <span class="k">else</span>
</div><div id="l1168" class="code_block">    <span class="p">{</span>
</div><div id="l1169" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">b</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="p">)</span> 
</div><div id="l1170" class="code_block">	<span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l1171" class="code_block">	  <span class="p">(</span><span class="s">&quot;can not treat matrix inversion&quot;</span><span class="p">);</span>
</div><div id="l1172" class="code_block">
</div><div id="l1173" class="code_block">      <span class="n">FixedMatrix</span> <span class="n">atmp</span> <span class="p">(</span><span class="n">a</span><span class="p">);</span>
</div><div id="l1174" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="n">atmp</span><span class="p">;</span>
</div><div id="l1175" class="code_block">      <span class="n">b</span><span class="o">--</span><span class="p">;</span>
</div><div id="l1176" class="code_block">      <span class="k">while</span> <span class="p">(</span><span class="n">b</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l1177" class="code_block">	<span class="p">{</span>
</div><div id="l1178" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">b</span> <span class="o">&amp;</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l1179" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="n">retval</span> <span class="o">*</span> <span class="n">atmp</span><span class="p">;</span>
</div><div id="l1180" class="code_block">
</div><div id="l1181" class="code_block">	  <span class="n">b</span> <span class="o">&gt;&gt;=</span> <span class="mi">1</span><span class="p">;</span>
</div><div id="l1182" class="code_block">
</div><div id="l1183" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">b</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l1184" class="code_block">	    <span class="n">atmp</span> <span class="o">=</span> <span class="n">atmp</span> <span class="o">*</span> <span class="n">atmp</span><span class="p">;</span>
</div><div id="l1185" class="code_block">	<span class="p">}</span>
</div><div id="l1186" class="code_block">    <span class="p">}</span>
</div><div id="l1187" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1188" class="code_block"><span class="p">}</span>
</div><div id="l1189" class="code_block">
</div><div id="l1190" class="code_block"><span class="n">FixedMatrix</span> <span class="n">pow</span>  <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="kt">double</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l1191" class="code_block"><span class="p">{</span>
</div><div id="l1192" class="code_block">  <span class="kt">int</span> <span class="n">bi</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">b</span><span class="p">;</span>
</div><div id="l1193" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="kt">double</span><span class="p">)</span><span class="n">bi</span> <span class="o">!=</span> <span class="n">b</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1194" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l1195" class="code_block">      <span class="p">(</span><span class="s">&quot;can only treat integer powers of a matrix&quot;</span><span class="p">);</span>
</div><div id="l1196" class="code_block">    <span class="k">return</span> <span class="n">FixedMatrix</span><span class="p">();</span>
</div><div id="l1197" class="code_block">  <span class="p">}</span>
</div><div id="l1198" class="code_block">
</div><div id="l1199" class="code_block">  <span class="k">return</span> <span class="n">pow</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">bi</span><span class="p">);</span>
</div><div id="l1200" class="code_block"><span class="p">}</span>
</div><div id="l1201" class="code_block">
</div><div id="l1202" class="code_block"><span class="n">FixedMatrix</span> <span class="n">pow</span>  <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedPoint</span> <span class="o">&amp;</span><span class="n">b</span><span class="p">)</span>
</div><div id="l1203" class="code_block"><span class="p">{</span>
</div><div id="l1204" class="code_block">  <span class="k">return</span> <span class="n">pow</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">.</span><span class="n">fixedpoint</span><span class="p">());</span>
</div><div id="l1205" class="code_block"><span class="p">}</span>
</div><div id="l1206" class="code_block">
</div><div id="l1207" class="code_block"><span class="n">FixedMatrix</span> <span class="n">pow</span>  <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">b</span><span class="p">)</span>
</div><div id="l1208" class="code_block"><span class="p">{</span>
</div><div id="l1209" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">||</span> 
</div><div id="l1210" class="code_block">      <span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">1</span> <span class="o">||</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1211" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l1212" class="code_block">      <span class="p">(</span><span class="s">&quot;for A^x, A must be square and x scalar&quot;</span><span class="p">);</span>
</div><div id="l1213" class="code_block">    <span class="k">return</span> <span class="n">FixedMatrix</span><span class="p">();</span>
</div><div id="l1214" class="code_block">  <span class="p">}</span> <span class="k">else</span>
</div><div id="l1215" class="code_block">    <span class="k">return</span> <span class="n">pow</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">).</span><span class="n">fixedpoint</span><span class="p">());</span>
</div><div id="l1216" class="code_block"><span class="p">}</span>
</div><div id="l1217" class="code_block">
</div><div id="l1218" class="code_block"><span class="n">FixedMatrix</span> <span class="n">atan2</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">)</span>
</div><div id="l1219" class="code_block"><span class="p">{</span>
</div><div id="l1220" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1221" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">x</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="n">y</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">x</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="n">y</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l1222" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">x</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">x</span><span class="p">.</span><span class="n">cols</span><span class="p">());</span>
</div><div id="l1223" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">x</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1224" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">x</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1225" class="code_block">	<span class="n">retval</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">atan2</span> <span class="p">(</span> <span class="n">x</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">),</span> <span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l1226" class="code_block">  <span class="p">}</span> <span class="k">else</span>
</div><div id="l1227" class="code_block">    <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span> <span class="p">(</span><span class="s">&quot;matrix size mismatch&quot;</span><span class="p">);</span>
</div><div id="l1228" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1229" class="code_block"><span class="p">}</span>
</div><div id="l1230" class="code_block">
</div><div id="l1231" class="code_block"><span class="n">std</span><span class="o">::</span><span class="n">ostream</span><span class="o">&amp;</span>
</div><div id="l1232" class="code_block"><span class="k">operator</span> <span class="o">&lt;&lt;</span> <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">ostream</span><span class="o">&amp;</span> <span class="n">os</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l1233" class="code_block"><span class="p">{</span>
</div><div id="l1234" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1235" class="code_block">    <span class="p">{</span>
</div><div id="l1236" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1237" class="code_block">	<span class="p">{</span>
</div><div id="l1238" class="code_block">	  <span class="n">os</span> <span class="o">&lt;&lt;</span> <span class="s">&quot; &quot;</span> <span class="o">&lt;&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l1239" class="code_block">	<span class="p">}</span>
</div><div id="l1240" class="code_block">      <span class="n">os</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">;</span>
</div><div id="l1241" class="code_block">    <span class="p">}</span>
</div><div id="l1242" class="code_block">  <span class="k">return</span> <span class="n">os</span><span class="p">;</span>
</div><div id="l1243" class="code_block"><span class="p">}</span>
</div><div id="l1244" class="code_block">
</div><div id="l1245" class="code_block"><span class="n">std</span><span class="o">::</span><span class="n">istream</span><span class="o">&amp;</span>
</div><div id="l1246" class="code_block"><span class="k">operator</span> <span class="o">&gt;&gt;</span> <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">istream</span><span class="o">&amp;</span> <span class="n">is</span><span class="p">,</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">)</span>
</div><div id="l1247" class="code_block"><span class="p">{</span>
</div><div id="l1248" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1249" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span>
</div><div id="l1250" class="code_block">
</div><div id="l1251" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">&lt;</span> <span class="mi">1</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">&lt;</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l1252" class="code_block">    <span class="n">is</span><span class="p">.</span><span class="n">clear</span> <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">ios</span><span class="o">::</span><span class="n">badbit</span><span class="p">);</span>
</div><div id="l1253" class="code_block">  <span class="k">else</span>
</div><div id="l1254" class="code_block">    <span class="p">{</span>
</div><div id="l1255" class="code_block">      <span class="n">FixedPoint</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l1256" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1257" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1258" class="code_block">	  <span class="p">{</span>
</div><div id="l1259" class="code_block">	    <span class="n">is</span> <span class="o">&gt;&gt;</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l1260" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="n">is</span><span class="p">)</span>
</div><div id="l1261" class="code_block">	      <span class="n">a</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp</span><span class="p">;</span>
</div><div id="l1262" class="code_block">	    <span class="k">else</span>
</div><div id="l1263" class="code_block">	      <span class="k">goto</span> <span class="n">done</span><span class="p">;</span>
</div><div id="l1264" class="code_block">	  <span class="p">}</span>
</div><div id="l1265" class="code_block">    <span class="p">}</span>
</div><div id="l1266" class="code_block">
</div><div id="l1267" class="code_block"> <span class="nl">done:</span>
</div><div id="l1268" class="code_block">
</div><div id="l1269" class="code_block">  <span class="k">return</span> <span class="n">is</span><span class="p">;</span>
</div><div id="l1270" class="code_block"><span class="p">}</span>
</div><div id="l1271" class="code_block">
</div><div id="l1272" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1273" class="code_block"><span class="k">operator</span> <span class="o">*</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l1274" class="code_block"><span class="p">{</span>
</div><div id="l1275" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1276" class="code_block">
</div><div id="l1277" class="code_block">  <span class="kt">int</span> <span class="n">a_nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1278" class="code_block">  <span class="kt">int</span> <span class="n">a_nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span>
</div><div id="l1279" class="code_block">
</div><div id="l1280" class="code_block">  <span class="kt">int</span> <span class="n">b_nr</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1281" class="code_block">  <span class="kt">int</span> <span class="n">b_nc</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span> <span class="p">();</span>
</div><div id="l1282" class="code_block">
</div><div id="l1283" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">a_nc</span> <span class="o">!=</span> <span class="n">b_nr</span><span class="p">)</span>
</div><div id="l1284" class="code_block">    <span class="n">gripe_nonconformant</span> <span class="p">(</span><span class="s">&quot;operator *&quot;</span><span class="p">,</span> <span class="n">a_nr</span><span class="p">,</span> <span class="n">a_nc</span><span class="p">,</span> <span class="n">b_nr</span><span class="p">,</span> <span class="n">b_nc</span><span class="p">);</span>
</div><div id="l1285" class="code_block">  <span class="k">else</span>
</div><div id="l1286" class="code_block">    <span class="p">{</span>
</div><div id="l1287" class="code_block">      <span class="n">retval</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">a_nr</span><span class="p">,</span> <span class="n">b_nc</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">());</span>
</div><div id="l1288" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">a_nr</span> <span class="o">!=</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">a_nc</span> <span class="o">!=</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">b_nc</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l1289" class="code_block">	<span class="p">{</span>
</div><div id="l1290" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span>  <span class="n">b_nr</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span> 
</div><div id="l1291" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span>  <span class="n">b_nc</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1292" class="code_block">	      <span class="n">FixedPoint</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">);</span>
</div><div id="l1293" class="code_block">	      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">k</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">k</span> <span class="o">&lt;</span>  <span class="n">a_nr</span><span class="p">;</span> <span class="n">k</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1294" class="code_block">		<span class="n">retval</span><span class="p">.</span><span class="n">elem</span> <span class="p">(</span><span class="n">k</span><span class="p">,</span><span class="n">i</span><span class="p">)</span> <span class="o">+=</span> <span class="n">a</span><span class="p">.</span><span class="n">elem</span><span class="p">(</span><span class="n">k</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">*</span> <span class="n">tmp</span><span class="p">;</span> 
</div><div id="l1295" class="code_block">	    <span class="p">}</span>
</div><div id="l1296" class="code_block">	<span class="p">}</span>
</div><div id="l1297" class="code_block">    <span class="p">}</span>
</div><div id="l1298" class="code_block">
</div><div id="l1299" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1300" class="code_block"><span class="p">}</span>
</div><div id="l1301" class="code_block">
</div><div id="l1302" class="code_block"><span class="c1">// XXX FIXME XXX -- it would be nice to share code among the min/max</span>
</div><div id="l1303" class="code_block"><span class="c1">// functions below.</span>
</div><div id="l1304" class="code_block">
</div><div id="l1305" class="code_block"><span class="cp">#define EMPTY_RETURN_CHECK(T) \</span>
</div><div id="l1306" class="code_block"><span class="cp">  if (nr == 0 || nc == 0) \</span>
</div><div id="l1307" class="code_block"><span class="cp">    return T (nr, nc);</span>
</div><div id="l1308" class="code_block">
</div><div id="l1309" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1310" class="code_block"><span class="n">min</span> <span class="p">(</span><span class="n">FixedPoint</span> <span class="n">d</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">m</span><span class="p">)</span>
</div><div id="l1311" class="code_block"><span class="p">{</span>
</div><div id="l1312" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1313" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l1314" class="code_block">
</div><div id="l1315" class="code_block">  <span class="n">EMPTY_RETURN_CHECK</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">);</span>
</div><div id="l1316" class="code_block">
</div><div id="l1317" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l1318" class="code_block">
</div><div id="l1319" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1320" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1321" class="code_block">      <span class="p">{</span>
</div><div id="l1322" class="code_block">	<span class="n">OCTAVE_QUIT</span><span class="p">;</span>
</div><div id="l1323" class="code_block">	<span class="n">result</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="n">d</span> <span class="o">?</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">:</span> <span class="n">d</span><span class="p">;</span>
</div><div id="l1324" class="code_block">      <span class="p">}</span>
</div><div id="l1325" class="code_block">
</div><div id="l1326" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1327" class="code_block"><span class="p">}</span>
</div><div id="l1328" class="code_block">
</div><div id="l1329" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1330" class="code_block"><span class="n">min</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">m</span><span class="p">,</span> <span class="n">FixedPoint</span> <span class="n">d</span><span class="p">)</span>
</div><div id="l1331" class="code_block"><span class="p">{</span>
</div><div id="l1332" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1333" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l1334" class="code_block">
</div><div id="l1335" class="code_block">  <span class="n">EMPTY_RETURN_CHECK</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">);</span>
</div><div id="l1336" class="code_block">
</div><div id="l1337" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l1338" class="code_block">
</div><div id="l1339" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1340" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1341" class="code_block">      <span class="p">{</span>
</div><div id="l1342" class="code_block">	<span class="n">OCTAVE_QUIT</span><span class="p">;</span>
</div><div id="l1343" class="code_block">	<span class="n">result</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="n">d</span> <span class="o">?</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">:</span> <span class="n">d</span><span class="p">;</span>
</div><div id="l1344" class="code_block">      <span class="p">}</span>
</div><div id="l1345" class="code_block">
</div><div id="l1346" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1347" class="code_block"><span class="p">}</span>
</div><div id="l1348" class="code_block">
</div><div id="l1349" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1350" class="code_block"><span class="n">min</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l1351" class="code_block"><span class="p">{</span>
</div><div id="l1352" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1353" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l1354" class="code_block">
</div><div id="l1355" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span> <span class="p">()</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">columns</span> <span class="p">())</span>
</div><div id="l1356" class="code_block">    <span class="p">{</span>
</div><div id="l1357" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l1358" class="code_block">	<span class="p">(</span><span class="s">&quot;two-arg min expecting args of same size&quot;</span><span class="p">);</span>
</div><div id="l1359" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l1360" class="code_block">    <span class="p">}</span>
</div><div id="l1361" class="code_block">
</div><div id="l1362" class="code_block">  <span class="n">EMPTY_RETURN_CHECK</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">);</span>
</div><div id="l1363" class="code_block">
</div><div id="l1364" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l1365" class="code_block">
</div><div id="l1366" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1367" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1368" class="code_block">      <span class="p">{</span>
</div><div id="l1369" class="code_block">	<span class="n">OCTAVE_QUIT</span><span class="p">;</span>
</div><div id="l1370" class="code_block">	<span class="n">result</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">?</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">:</span> <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l1371" class="code_block">      <span class="p">}</span>
</div><div id="l1372" class="code_block">
</div><div id="l1373" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1374" class="code_block"><span class="p">}</span>
</div><div id="l1375" class="code_block">
</div><div id="l1376" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1377" class="code_block"><span class="n">max</span> <span class="p">(</span><span class="n">FixedPoint</span> <span class="n">d</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">m</span><span class="p">)</span>
</div><div id="l1378" class="code_block"><span class="p">{</span>
</div><div id="l1379" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1380" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l1381" class="code_block">
</div><div id="l1382" class="code_block">  <span class="n">EMPTY_RETURN_CHECK</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">);</span>
</div><div id="l1383" class="code_block">
</div><div id="l1384" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l1385" class="code_block">
</div><div id="l1386" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1387" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1388" class="code_block">      <span class="p">{</span>
</div><div id="l1389" class="code_block">	<span class="n">OCTAVE_QUIT</span><span class="p">;</span>
</div><div id="l1390" class="code_block">	<span class="n">result</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&gt;</span> <span class="n">d</span> <span class="o">?</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">:</span> <span class="n">d</span><span class="p">;</span>
</div><div id="l1391" class="code_block">      <span class="p">}</span>
</div><div id="l1392" class="code_block">
</div><div id="l1393" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1394" class="code_block"><span class="p">}</span>
</div><div id="l1395" class="code_block">
</div><div id="l1396" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1397" class="code_block"><span class="n">max</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">m</span><span class="p">,</span> <span class="n">FixedPoint</span> <span class="n">d</span><span class="p">)</span>
</div><div id="l1398" class="code_block"><span class="p">{</span>
</div><div id="l1399" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1400" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l1401" class="code_block">
</div><div id="l1402" class="code_block">  <span class="n">EMPTY_RETURN_CHECK</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">);</span>
</div><div id="l1403" class="code_block">
</div><div id="l1404" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l1405" class="code_block">
</div><div id="l1406" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1407" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1408" class="code_block">      <span class="p">{</span>
</div><div id="l1409" class="code_block">	<span class="n">OCTAVE_QUIT</span><span class="p">;</span>
</div><div id="l1410" class="code_block">	<span class="n">result</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&gt;</span> <span class="n">d</span> <span class="o">?</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">:</span> <span class="n">d</span><span class="p">;</span>
</div><div id="l1411" class="code_block">      <span class="p">}</span>
</div><div id="l1412" class="code_block">
</div><div id="l1413" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1414" class="code_block"><span class="p">}</span>
</div><div id="l1415" class="code_block">
</div><div id="l1416" class="code_block"><span class="n">FixedMatrix</span>
</div><div id="l1417" class="code_block"><span class="n">max</span> <span class="p">(</span><span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">FixedMatrix</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l1418" class="code_block"><span class="p">{</span>
</div><div id="l1419" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l1420" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l1421" class="code_block">
</div><div id="l1422" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span> <span class="p">()</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">!=</span> <span class="n">b</span><span class="p">.</span><span class="n">columns</span> <span class="p">())</span>
</div><div id="l1423" class="code_block">    <span class="p">{</span>
</div><div id="l1424" class="code_block">      <span class="p">(</span><span class="o">*</span><span class="n">current_liboctave_error_handler</span><span class="p">)</span>
</div><div id="l1425" class="code_block">	<span class="p">(</span><span class="s">&quot;two-arg max expecting args of same size&quot;</span><span class="p">);</span>
</div><div id="l1426" class="code_block">      <span class="k">return</span> <span class="n">FixedMatrix</span> <span class="p">();</span>
</div><div id="l1427" class="code_block">    <span class="p">}</span>
</div><div id="l1428" class="code_block">
</div><div id="l1429" class="code_block">  <span class="n">EMPTY_RETURN_CHECK</span> <span class="p">(</span><span class="n">FixedMatrix</span><span class="p">);</span>
</div><div id="l1430" class="code_block">
</div><div id="l1431" class="code_block">  <span class="n">FixedMatrix</span> <span class="n">result</span> <span class="p">(</span><span class="n">nr</span><span class="p">,</span> <span class="n">nc</span><span class="p">);</span>
</div><div id="l1432" class="code_block">
</div><div id="l1433" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1434" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1435" class="code_block">      <span class="p">{</span>
</div><div id="l1436" class="code_block">	<span class="n">OCTAVE_QUIT</span><span class="p">;</span>
</div><div id="l1437" class="code_block">	<span class="n">result</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&gt;</span> <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">?</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">:</span> <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l1438" class="code_block">      <span class="p">}</span>
</div><div id="l1439" class="code_block">
</div><div id="l1440" class="code_block">  <span class="k">return</span> <span class="n">result</span><span class="p">;</span>
</div><div id="l1441" class="code_block"><span class="p">}</span>
</div><div id="l1442" class="code_block">
</div><div id="l1443" class="code_block"><span class="n">MS_CMP_OPS</span><span class="p">(</span><span class="n">FixedMatrix</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">)</span>
</div><div id="l1444" class="code_block"><span class="n">MS_BOOL_OPS</span><span class="p">(</span><span class="n">FixedMatrix</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">)</span>
</div><div id="l1445" class="code_block">
</div><div id="l1446" class="code_block"><span class="n">SM_CMP_OPS</span><span class="p">(</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedMatrix</span><span class="p">)</span>
</div><div id="l1447" class="code_block"><span class="n">SM_BOOL_OPS</span><span class="p">(</span><span class="n">FixedPoint</span><span class="p">,</span> <span class="n">FixedMatrix</span><span class="p">)</span>
</div><div id="l1448" class="code_block">
</div><div id="l1449" class="code_block"><span class="n">MM_CMP_OPS</span><span class="p">(</span><span class="n">FixedMatrix</span><span class="p">,</span> <span class="n">FixedMatrix</span><span class="p">)</span>
</div><div id="l1450" class="code_block"><span class="n">MM_BOOL_OPS</span><span class="p">(</span><span class="n">FixedMatrix</span><span class="p">,</span> <span class="n">FixedMatrix</span><span class="p">)</span>
</div><div id="l1451" class="code_block">
</div><div id="l1452" class="code_block"><span class="cm">/*</span>
</div><div id="l1453" class="code_block"><span class="cm">;;; Local Variables: ***</span>
</div><div id="l1454" class="code_block"><span class="cm">;;; mode: C++ ***</span>
</div><div id="l1455" class="code_block"><span class="cm">;;; End: ***</span>
</div><div id="l1456" class="code_block"><span class="cm">*/</span>
</div></pre></div>
</td></tr></table>
      
    </div>
  

          </div>
			
          
        </div>
      </div>
    </section>
      
<footer id="site-footer">
    <div class="wrapper">
        <nav>
            <h5>SourceForge</h5>
            <a href="/about">About</a>
            <a href="/blog/category/sitestatus/">Site Status</a>
            <a href="http://twitter.com/sfnet_ops">@sfnet_ops</a>
        </nav>
        <nav>
            <h5>Find and Develop Software</h5>
            <a href="/create/">Create a Project</a>
            <a href="/directory/">Software Directory</a>
            <a href="/top">Top Downloaded Projects</a>
        </nav>
        <nav>
            <h5>Community</h5>
            <a href="/blog/">Blog</a>
            <a href="http://twitter.com/sourceforge">@sourceforge</a>
            <a href="http://seeker.dice.com/jobsearch/servlet/JobSearch?caller=0&amp;source=76&amp;LOCATION_OPTION=2&amp;EXTRA_STUFF=0&amp;N=0&amp;Hf=0&amp;Ntk=JobSearchRanking&amp;op=300&amp;values=&amp;FREE_TEXT=&amp;Ntx=mode+matchall&amp;EXCLUDE_KEY1=p_JobTitle&amp;EXCLUDE_TEXT1=&amp;EXCLUDE_KEY2=p_JobTitle&amp;EXCLUDE_TEXT2=&amp;EXCLUDE_KEY3=p_JobTitle&amp;EXCLUDE_TEXT3=&amp;EXCLUDE_KEY4=p_JobTitle&amp;EXCLUDE_TEXT4=&amp;EXCLUDE_KEY5=p_JobTitle&amp;EXCLUDE_TEXT5=&amp;EXCLUDE_KEY6=p_JobTitle&amp;EXCLUDE_TEXT6=&amp;EXCLUDE_KEY7=p_JobTitle&amp;EXCLUDE_TEXT7=&amp;EXCLUDE_KEY8=p_JobTitle&amp;EXCLUDE_TEXT8=&amp;locationRadio=on&amp;RADIUS=64.37376&amp;WHERE=&amp;COUNTRY=1525&amp;STAT_PROV=0&amp;METRO_AREA=33.78715899%2C-84.39164034&amp;AREA_CODES=&amp;AC_COUNTRY=1525&amp;TRAVEL=0&amp;TAXTERM=0&amp;SORTSPEC=0&amp;FRMT=0&amp;DAYSBACK=30&amp;NUM_PER_PAGE=30&amp;source_page=allura">Job Board</a>
        </nav>
        <nav>
            <h5>Help</h5>
            <a href="/apps/trac/sourceforge/wiki/WikiStart">Site Documentation</a>
            <a href="/support">Support Request</a>
            <a href="https://sourceforge.net/p/forge/documentation/Support%20via%20IRC/">Real-Time Support</a>
        </nav>
    </div>
</footer>
<footer id="site-copyright-footer">
    <div class="wrapper">
        <div id="copyright">
            Copyright &copy; 2012 SourceForge. All Rights Reserved.<br />
            SourceForge is a <a href="http://www.diceholdingsinc.com/phoenix.zhtml?c=211152&amp;p=irol-landing">Dice Holdings, Inc.</a> company.
        </div>
        <nav>
            <a href="http://geeknetmedia.com/terms-of-use">Terms</a>
            <a href="http://geeknetmedia.com/privacy-statement/">Privacy</a>
            <a href="http://geeknetmedia.com/opt-out-choices">Cookies/Opt Out</a>
            <a href="http://geeknetmedia.com">Advertise</a>
            <a href="http://sourceforge.jp/">SourceForge.JP</a>
        </nav>
    </div>
</footer>
    <div id="messages">
        
    </div>
    
      <!-- ew:body_js -->

    
      <script type="text/javascript" src="http://a.fsdn.com/allura/nf/1354307686/_ew_/_slim/js?href=allura%2Fjs%2Fjquery-base.js%3Ballura%2Fjs%2Fjquery.notify.js%3Ballura%2Fjs%2Fsylvester.js%3Ballura%2Fjs%2Fpb.transformie.min.js%3Ballura%2Fjs%2Fallura-base.js"></script>
    
      
<!-- /ew:body_js -->

    
    
      <!-- ew:body_js_tail -->

    
      
<!-- /ew:body_js_tail -->

    
    

<script type="text/javascript" src="http://a.fsdn.com/allura/nf/1354307686/_static_/js/spin.min.js"></script>
<script type="text/javascript">(function() {
  $('#access_urls .btn').click(function(evt){
    evt.preventDefault();
    var parent = $(this).parents('.btn-bar');
    $(parent).find('input').val($(this).attr('data-url'));
    $(parent).find('span').text($(this).attr('title')+' access');
    $(this).parent().children('.btn').removeClass('active');
    $(this).addClass('active');
  });
  $('#access_urls .btn').first().click();

  
  var repo_status = document.getElementById('repo_status');
  // The repo_status div will only be present if repo.status != 'ready'
  if (repo_status) {
    var opts = {
        lines: 9, // The number of lines to draw
        length: 4, // The length of each line
        width: 2, // The line thickness
        radius: 3, // The radius of the inner circle
        rotate: 0, // The rotation offset
        color: '#555', // #rgb or #rrggbb
        speed: 1, // Rounds per second
        trail: 60, // Afterglow percentage
        shadow: false, // Whether to render a shadow
        hwaccel: false, // Whether to use hardware acceleration
        className: 'spinner', // The CSS class to assign to the spinner
        zIndex: 2e9, // The z-index (defaults to 2000000000)
        top: 10, // Top position relative to parent in px
        left: 10 // Left position relative to parent in px
    };
    var spinner = new Spinner(opts).spin(repo_status);
    function check_status() {
        $.get('/p/octave/code/status', function(data) {
            if (data.status === 'ready') {
                window.clearInterval(status_checker);
                spinner.opts.speed = 0;
                spinner.opts.opacity = 1;
                spinner.spin(repo_status)
                $('#repo_status h2').html('Repo status: ready. <a href=".">Click here to refresh this page.</a>');
            }
            else {
                $('#repo_status h2 span').html(data.status);
            }
        });
    }
    // Check repo status every 15 seconds
    var status_checker = window.setInterval(check_status, 15000);
    
  }
}());
</script>

<script type="text/javascript">(function() {
  $(window).bind('hashchange', function(e) {
    var hash = window.location.hash.substring(1);
	if ('originalEvent' in e && 'oldURL' in e.originalEvent) {
      $('#' + e.originalEvent.oldURL.split('#')[1]).css('background-color', 'transparent');
	}
    if (hash !== '' && hash.substring(0, 1) === 'l' && !isNaN(hash.substring(1))) {
      $('#' + hash).css('background-color', '#ffff99');
    }
  }).trigger('hashchange');

  $('.code_block').each(function(index, element) {
    $(element).bind('click', function() {
      var hash = window.location.hash.substring(1);
      if (hash !== '' && hash.substring(0, 1) === 'l' && !isNaN(hash.substring(1))) {
        $('#' + hash).css('background-color', 'transparent');
      }
      $(element).css('background-color', '#ffff99');
      window.location.href = '#' + $(element).attr('id');
    });
  });
}());
</script>

    
      
    
    
   
    
  </body>
</html>