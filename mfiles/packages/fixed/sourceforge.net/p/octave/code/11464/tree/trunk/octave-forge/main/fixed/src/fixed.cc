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
  /trunk/octave-forge/main/fixed/src/fixed.cc
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

      <style>.XRAnqVAMirNFabHhzuucP { display:none }</style>

    
    
    
    


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
    
  
 fixed.cc

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
        <span class="ico-l"><b data-icon="n" class="ico ico-table"></b> fixed.cc</span>
        &nbsp;&nbsp;
        1162 lines (1074 with data), 42.3 kB
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
1161</pre></div></td><td class="code"><div class="codehilite"><pre><div id="l1" class="code_block"><span class="cm">/*</span>
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
</div><div id="l26" class="code_block"><span class="cp">#include &quot;ov-fixed.h&quot;</span>
</div><div id="l27" class="code_block"><span class="cp">#include &quot;ov-fixed-mat.h&quot;</span>
</div><div id="l28" class="code_block"><span class="cp">#include &quot;ov-fixed-complex.h&quot;</span>
</div><div id="l29" class="code_block"><span class="cp">#include &quot;ov-fixed-cx-mat.h&quot;</span>
</div><div id="l30" class="code_block"><span class="cp">#include &quot;fixed-var.h&quot;</span>
</div><div id="l31" class="code_block">
</div><div id="l32" class="code_block"><span class="cp">#include &lt;octave/variables.h&gt;</span>
</div><div id="l33" class="code_block"><span class="cp">#include &lt;octave/utils.h&gt;</span>
</div><div id="l34" class="code_block"><span class="cp">#include &lt;octave/pager.h&gt;</span>
</div><div id="l35" class="code_block"><span class="cp">#include &lt;octave/defun-dld.h&gt;</span>
</div><div id="l36" class="code_block"><span class="cp">#include &lt;octave/gripes.h&gt;</span>
</div><div id="l37" class="code_block">
</div><div id="l38" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fs_fs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l39" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fs_fm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l40" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fm_fs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l41" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fm_fm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l42" class="code_block">
</div><div id="l43" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fs_fcs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l44" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fs_fcm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l45" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fm_fcs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l46" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fm_fcm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l47" class="code_block">
</div><div id="l48" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcs_fs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l49" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcs_fm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l50" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcm_fs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l51" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcm_fm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l52" class="code_block">
</div><div id="l53" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcs_fcs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l54" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcs_fcm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l55" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcm_fcs_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l56" class="code_block"><span class="k">extern</span> <span class="kt">void</span> <span class="n">install_fcm_fcm_ops</span> <span class="p">(</span><span class="kt">void</span><span class="p">);</span>
</div><div id="l57" class="code_block">
</div><div id="l58" class="code_block"><span class="k">static</span> <span class="kt">bool</span> <span class="n">fixed_type_loaded</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l59" class="code_block">
</div><div id="l60" class="code_block"><span class="kt">void</span> <span class="n">load_fixed_type</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span>
</div><div id="l61" class="code_block"><span class="p">{</span>
</div><div id="l62" class="code_block">  <span class="n">octave_fixed</span><span class="o">::</span><span class="n">register_type</span> <span class="p">();</span>
</div><div id="l63" class="code_block">  <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">register_type</span> <span class="p">();</span>
</div><div id="l64" class="code_block">  <span class="n">octave_fixed_complex</span><span class="o">::</span><span class="n">register_type</span> <span class="p">();</span>
</div><div id="l65" class="code_block">  <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">register_type</span> <span class="p">();</span>
</div><div id="l66" class="code_block">
</div><div id="l67" class="code_block">  <span class="n">install_fs_fs_ops</span> <span class="p">();</span>
</div><div id="l68" class="code_block">  <span class="n">install_fs_fm_ops</span> <span class="p">();</span>
</div><div id="l69" class="code_block">  <span class="n">install_fm_fs_ops</span> <span class="p">();</span>
</div><div id="l70" class="code_block">  <span class="n">install_fm_fm_ops</span> <span class="p">();</span>
</div><div id="l71" class="code_block">
</div><div id="l72" class="code_block">  <span class="n">install_fs_fcs_ops</span> <span class="p">();</span>
</div><div id="l73" class="code_block">  <span class="n">install_fs_fcm_ops</span> <span class="p">();</span>
</div><div id="l74" class="code_block">  <span class="n">install_fm_fcs_ops</span> <span class="p">();</span>
</div><div id="l75" class="code_block">  <span class="n">install_fm_fcm_ops</span> <span class="p">();</span>
</div><div id="l76" class="code_block">
</div><div id="l77" class="code_block">  <span class="n">install_fcs_fs_ops</span> <span class="p">();</span>
</div><div id="l78" class="code_block">  <span class="n">install_fcs_fm_ops</span> <span class="p">();</span>
</div><div id="l79" class="code_block">  <span class="n">install_fcm_fs_ops</span> <span class="p">();</span>
</div><div id="l80" class="code_block">  <span class="n">install_fcm_fm_ops</span> <span class="p">();</span>
</div><div id="l81" class="code_block">
</div><div id="l82" class="code_block">  <span class="n">install_fcs_fcs_ops</span> <span class="p">();</span>
</div><div id="l83" class="code_block">  <span class="n">install_fcs_fcm_ops</span> <span class="p">();</span>
</div><div id="l84" class="code_block">  <span class="n">install_fcm_fcs_ops</span> <span class="p">();</span>
</div><div id="l85" class="code_block">  <span class="n">install_fcm_fcm_ops</span> <span class="p">();</span>
</div><div id="l86" class="code_block">
</div><div id="l87" class="code_block">  <span class="n">fixed_type_loaded</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l88" class="code_block">
</div><div id="l89" class="code_block">  <span class="n">mlock</span> <span class="p">();</span>
</div><div id="l90" class="code_block"><span class="p">}</span>
</div><div id="l91" class="code_block">
</div><div id="l92" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;display_fixed_operations&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l93" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">display_fixed_operations</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l94" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l95" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {} display_fixed_operations ( )</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l96" class="code_block"><span class="s">&quot;Displays out a summary of the number of fixed point operations of each</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l97" class="code_block"><span class="s">&quot;type that have been used. This can be used to give a estimate of the</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l98" class="code_block"><span class="s">&quot;complexity of an algorithm.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l99" class="code_block"><span class="s">&quot;@end deftypefn</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l100" class="code_block"><span class="s">&quot;@seealso{fixed_point_count_operations, reset_fixed_operations}&quot;</span><span class="p">)</span> 
</div><div id="l101" class="code_block"><span class="p">{</span>
</div><div id="l102" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l103" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">args</span><span class="p">.</span><span class="n">length</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span> <span class="o">||</span> <span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span>
</div><div id="l104" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l105" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">Fixed</span><span class="o">::</span><span class="n">FP_CountOperations</span><span class="p">)</span>
</div><div id="l106" class="code_block">    <span class="n">octave_stdout</span> <span class="o">&lt;&lt;</span> <span class="n">Fixed</span><span class="o">::</span><span class="n">FP_Operations</span><span class="p">;</span>
</div><div id="l107" class="code_block">  <span class="k">else</span>
</div><div id="l108" class="code_block">    <span class="n">error</span><span class="p">(</span><span class="s">&quot;display_fixed_operations: variable fixed_point_count_operations is zero&quot;</span><span class="p">);</span>
</div><div id="l109" class="code_block">
</div><div id="l110" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l111" class="code_block"><span class="p">}</span>
</div><div id="l112" class="code_block">
</div><div id="l113" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;reset_fixed_operations&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l114" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">reset_fixed_operations</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l115" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l116" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {} reset_fixed_operations ( )</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l117" class="code_block"><span class="s">&quot;Reset the count of fixed point operations to zero.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l118" class="code_block"><span class="s">&quot;@end deftypefn</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l119" class="code_block"><span class="s">&quot;@seealso{fixed_point_count_operations, display_fixed_operations}&quot;</span><span class="p">)</span> 
</div><div id="l120" class="code_block"><span class="p">{</span>
</div><div id="l121" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l122" class="code_block">  <span class="k">if</span> <span class="p">((</span><span class="n">args</span><span class="p">.</span><span class="n">length</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span> <span class="o">||</span> <span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span>
</div><div id="l123" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l124" class="code_block">  <span class="k">else</span>
</div><div id="l125" class="code_block">    <span class="n">Fixed</span><span class="o">::</span><span class="n">FP_Operations</span><span class="p">.</span><span class="n">reset</span><span class="p">();</span>
</div><div id="l126" class="code_block">    
</div><div id="l127" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l128" class="code_block"><span class="p">}</span>
</div><div id="l129" class="code_block">
</div><div id="l130" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;isfixed&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l131" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">isfixed</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l132" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l133" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {} isfixed (@var{expr})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l134" class="code_block"><span class="s">&quot;Return 1 if the value of the expression @var{expr} is a fixed point value.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l135" class="code_block"><span class="s">&quot;@end deftypefn&quot;</span><span class="p">)</span> 
</div><div id="l136" class="code_block"><span class="p">{</span>
</div><div id="l137" class="code_block">   <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">.</span><span class="n">length</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span> 
</div><div id="l138" class="code_block">     <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l139" class="code_block">   <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span>
</div><div id="l140" class="code_block">     <span class="c1">// Can&#39;t be of fixed type if the type isn&#39;t load :-/</span>
</div><div id="l141" class="code_block">     <span class="k">return</span> <span class="n">octave_value</span><span class="p">(</span><span class="kc">false</span><span class="p">);</span>
</div><div id="l142" class="code_block">   <span class="k">else</span> 
</div><div id="l143" class="code_block">     <span class="k">return</span> <span class="p">(</span><span class="n">octave_value</span><span class="p">((</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span>
</div><div id="l144" class="code_block">			   <span class="n">octave_fixed</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l145" class="code_block">			  <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span>
</div><div id="l146" class="code_block">			   <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l147" class="code_block">			  <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span>
</div><div id="l148" class="code_block">			   <span class="n">octave_fixed_complex</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l149" class="code_block">			  <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span>
</div><div id="l150" class="code_block">			   <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())));</span>
</div><div id="l151" class="code_block">   <span class="k">return</span> <span class="n">octave_value</span><span class="p">();</span>
</div><div id="l152" class="code_block"><span class="p">}</span>
</div><div id="l153" class="code_block">
</div><div id="l154" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">fixed</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="n">nargout</span><span class="p">,</span>
</div><div id="l155" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l156" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {@var{y} =} fixed (@var{f})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l157" class="code_block"><span class="s">&quot;@deftypefnx {Loadable Function} {@var{y} =} fixed (@var{is},@var{ds})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l158" class="code_block"><span class="s">&quot;@deftypefnx {Loadable Function} {@var{y} =} fixed (@var{is},@var{ds},@var{f})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l159" class="code_block"><span class="s">&quot;Used the create a fixed point variable. Called with a single argument, if</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l160" class="code_block"><span class="s">&quot;@var{f} is itself a fixed point value, then @dfn{fixed} is equivalent to</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l161" class="code_block"><span class="s">&quot;@code{@var{y} = @var{f}}. Otherwise the integer part of @var{f} is used</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l162" class="code_block"><span class="s">&quot;to create a fixed point variable with the minimum number of bits needed</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l163" class="code_block"><span class="s">&quot;to represent it. @var{f} can be either real of complex.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l164" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l165" class="code_block"><span class="s">&quot;Called with two or more arguments @var{is} represents the number of bits</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l166" class="code_block"><span class="s">&quot;used to represent the integer part of the fixed point numbers, and @var{ds}</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l167" class="code_block"><span class="s">&quot;the number used to represent the decimal part. These variables must be</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l168" class="code_block"><span class="s">&quot;either positive integer scalars or matrices. If they are matrices they</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l169" class="code_block"><span class="s">&quot;must be of the same dimension, and each fixed point number in the created</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l170" class="code_block"><span class="s">&quot;matrix will have the representation given by the corresponding values of</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l171" class="code_block"><span class="s">&quot;@var{is} and @var{ds}.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l172" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l173" class="code_block"><span class="s">&quot;When creating complex fixed point values, the fixed point representation</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l174" class="code_block"><span class="s">&quot;can be different for the real and imaginary parts. In this case @var{is}</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l175" class="code_block"><span class="s">&quot;and @var{ds} are complex integers.&quot;</span>
</div><div id="l176" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l177" class="code_block"><span class="s">&quot;Additionally the maximum value of the sum of @var{is} and @var{ds} is</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l178" class="code_block"><span class="s">&quot;limited by the representation of long integers to either 30 or 62.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l179" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l180" class="code_block"><span class="s">&quot;Called with only two arguments, the fixed point variable that is created</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l181" class="code_block"><span class="s">&quot;will contain only zeros. A third argument can be used to give the values</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l182" class="code_block"><span class="s">&quot;of the fixed variables elements. This third argument @var{f} can be either</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l183" class="code_block"><span class="s">&quot;a fixed point variable itself, which results in a new fixed point variable</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l184" class="code_block"><span class="s">&quot;being created with a different representation, or a real or complex matrix.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l185" class="code_block"><span class="s">&quot;@end deftypefn</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">)</span>
</div><div id="l186" class="code_block"><span class="p">{</span>
</div><div id="l187" class="code_block">  <span class="kt">int</span> <span class="n">nargin</span> <span class="o">=</span> <span class="n">args</span><span class="p">.</span><span class="n">length</span><span class="p">();</span>
</div><div id="l188" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l189" class="code_block">
</div><div id="l190" class="code_block">  <span class="k">if</span> <span class="p">(</span> <span class="n">nargin</span> <span class="o">==</span> <span class="mi">0</span> <span class="p">)</span> <span class="p">{</span>
</div><div id="l191" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l192" class="code_block">  <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">1</span> <span class="p">)</span> <span class="p">{</span>
</div><div id="l193" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span> <span class="o">&amp;&amp;</span>
</div><div id="l194" class="code_block">	<span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l195" class="code_block">      <span class="n">FixedMatrix</span> <span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span>
</div><div id="l196" class="code_block">	<span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l197" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l198" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span> <span class="o">&amp;&amp;</span>
</div><div id="l199" class="code_block">	       <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l200" class="code_block">      <span class="n">FixedPoint</span> <span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_value</span><span class="p">();</span>
</div><div id="l201" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l202" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span> <span class="o">&amp;&amp;</span>
</div><div id="l203" class="code_block">           <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l204" class="code_block">      <span class="n">FixedPointComplex</span> <span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex</span><span class="o">&amp;</span><span class="p">)</span> 
</div><div id="l205" class="code_block">		      <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_complex_value</span><span class="p">();</span>
</div><div id="l206" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l207" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span> <span class="o">&amp;&amp;</span>
</div><div id="l208" class="code_block">	       <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l209" class="code_block">		<span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l210" class="code_block">      <span class="n">FixedComplexMatrix</span> <span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span> 
</div><div id="l211" class="code_block">		      <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l212" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l213" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l214" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">())</span> <span class="p">{</span>
</div><div id="l215" class="code_block">	<span class="n">ComplexMatrix</span> <span class="n">a</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">complex_matrix_value</span><span class="p">();</span>
</div><div id="l216" class="code_block">	<span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">b</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l217" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l218" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l219" class="code_block">	    <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">real</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l220" class="code_block">	<span class="n">FixedMatrix</span> <span class="n">fr</span><span class="p">(</span><span class="n">b</span><span class="p">);</span>
</div><div id="l221" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l222" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l223" class="code_block">	    <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">imag</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l224" class="code_block">	<span class="n">FixedMatrix</span> <span class="n">fi</span><span class="p">(</span><span class="n">b</span><span class="p">);</span>
</div><div id="l225" class="code_block">	<span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">fr</span><span class="p">,</span> <span class="n">fi</span><span class="p">);</span>
</div><div id="l226" class="code_block">      <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l227" class="code_block">	<span class="n">Matrix</span> <span class="n">a</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">matrix_value</span><span class="p">();</span>
</div><div id="l228" class="code_block">	<span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">b</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l229" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l230" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l231" class="code_block">	    <span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l232" class="code_block">	<span class="n">FixedMatrix</span> <span class="n">f</span><span class="p">(</span><span class="n">b</span><span class="p">);</span>
</div><div id="l233" class="code_block">	<span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l234" class="code_block">      <span class="p">}</span>
</div><div id="l235" class="code_block">    <span class="p">}</span>
</div><div id="l236" class="code_block">  <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">((</span><span class="n">nargin</span> <span class="o">==</span><span class="mi">2</span><span class="p">)</span> <span class="o">||</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">3</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l237" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">()</span> <span class="o">||</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">()</span> <span class="o">||</span> 
</div><div id="l238" class="code_block">	<span class="p">((</span><span class="n">nargin</span> <span class="o">&gt;</span> <span class="mi">2</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="n">args</span><span class="p">(</span><span class="mi">2</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l239" class="code_block">
</div><div id="l240" class="code_block">      <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">mir</span><span class="p">,</span> <span class="n">mii</span><span class="p">,</span> <span class="n">mdr</span><span class="p">,</span> <span class="n">mdi</span><span class="p">;</span>
</div><div id="l241" class="code_block">      <span class="n">ComplexMatrix</span> <span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">;</span>
</div><div id="l242" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">())</span>
</div><div id="l243" class="code_block">	<span class="n">a</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">complex_matrix_value</span><span class="p">();</span>
</div><div id="l244" class="code_block">      <span class="k">else</span> <span class="p">{</span>
</div><div id="l245" class="code_block">	<span class="n">a</span> <span class="o">=</span> <span class="n">ComplexMatrix</span><span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">matrix_value</span><span class="p">());</span>
</div><div id="l246" class="code_block">	<span class="n">a</span> <span class="o">=</span> <span class="n">a</span> <span class="o">+</span> <span class="n">Complex</span><span class="p">(</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">)</span><span class="o">*</span><span class="n">a</span><span class="p">;</span>
</div><div id="l247" class="code_block">      <span class="p">}</span>
</div><div id="l248" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">())</span>
</div><div id="l249" class="code_block">	<span class="n">b</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">complex_matrix_value</span><span class="p">();</span>
</div><div id="l250" class="code_block">      <span class="k">else</span> <span class="p">{</span>
</div><div id="l251" class="code_block">	<span class="n">b</span> <span class="o">=</span> <span class="n">ComplexMatrix</span><span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">matrix_value</span><span class="p">());</span>
</div><div id="l252" class="code_block">	<span class="n">b</span> <span class="o">=</span> <span class="n">b</span> <span class="o">+</span> <span class="n">Complex</span><span class="p">(</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">)</span><span class="o">*</span><span class="n">b</span><span class="p">;</span>
</div><div id="l253" class="code_block">      <span class="p">}</span>
</div><div id="l254" class="code_block">
</div><div id="l255" class="code_block">      <span class="n">mir</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l256" class="code_block">      <span class="n">mii</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l257" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l258" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l259" class="code_block">	  <span class="n">mir</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="n">real</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l260" class="code_block">	  <span class="n">mii</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="n">imag</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l261" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">std</span><span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span><span class="o">-</span><span class="p">(</span><span class="kt">double</span><span class="p">)</span><span class="n">mir</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span> <span class="o">!=</span> <span class="mf">0.</span><span class="p">)</span> <span class="o">||</span> 
</div><div id="l262" class="code_block">	      <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span><span class="o">-</span><span class="p">(</span><span class="kt">double</span><span class="p">)</span><span class="n">mii</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span> <span class="o">!=</span> <span class="mf">0.</span><span class="p">)</span> <span class="o">||</span> 
</div><div id="l263" class="code_block">	      <span class="p">(</span><span class="n">mir</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="o">||</span> <span class="p">(</span><span class="n">mii</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l264" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: invalid fixed point representation&quot;</span><span class="p">);</span>
</div><div id="l265" class="code_block">	    <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l266" class="code_block">	  <span class="p">}</span>
</div><div id="l267" class="code_block">	<span class="p">}</span>
</div><div id="l268" class="code_block">
</div><div id="l269" class="code_block">      <span class="n">mdr</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l270" class="code_block">      <span class="n">mdi</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l271" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l272" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l273" class="code_block">	  <span class="n">mdr</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="n">real</span><span class="p">(</span><span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l274" class="code_block">	  <span class="n">mdi</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="n">imag</span><span class="p">(</span><span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">));</span>
</div><div id="l275" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">std</span><span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span><span class="o">-</span><span class="p">(</span><span class="kt">double</span><span class="p">)</span><span class="n">mdr</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span> <span class="o">!=</span> <span class="mf">0.</span><span class="p">)</span> <span class="o">||</span> 
</div><div id="l276" class="code_block">	      <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span><span class="o">-</span><span class="p">(</span><span class="kt">double</span><span class="p">)</span><span class="n">mdi</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span> <span class="o">!=</span> <span class="mf">0.</span><span class="p">)</span> <span class="o">||</span> 
</div><div id="l277" class="code_block">	      <span class="p">(</span><span class="n">mir</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="o">||</span> <span class="p">(</span><span class="n">mdi</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l278" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: invalid fixed point representation&quot;</span><span class="p">);</span>
</div><div id="l279" class="code_block">	    <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l280" class="code_block">	  <span class="p">}</span>
</div><div id="l281" class="code_block">	<span class="p">}</span>
</div><div id="l282" class="code_block">
</div><div id="l283" class="code_block">      <span class="k">if</span> <span class="p">((</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l284" class="code_block">	<span class="n">mir</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">mdr</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">mdr</span><span class="p">.</span><span class="n">cols</span><span class="p">()),</span> <span class="n">mir</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l285" class="code_block">	<span class="n">mii</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">mdr</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">mdr</span><span class="p">.</span><span class="n">cols</span><span class="p">()),</span> <span class="n">mii</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l286" class="code_block">      <span class="p">}</span>
</div><div id="l287" class="code_block">      <span class="k">if</span> <span class="p">((</span><span class="n">mdr</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mdr</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l288" class="code_block">	<span class="n">mdr</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()),</span> <span class="n">mdr</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l289" class="code_block">	<span class="n">mdi</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()),</span> <span class="n">mdi</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l290" class="code_block">      <span class="p">}</span>
</div><div id="l291" class="code_block">
</div><div id="l292" class="code_block">      <span class="k">if</span> <span class="p">((</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">mdr</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">mdr</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l293" class="code_block">	<span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: dimension mismatch in args&quot;</span><span class="p">);</span>
</div><div id="l294" class="code_block">	<span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l295" class="code_block">      <span class="p">}</span>
</div><div id="l296" class="code_block">    
</div><div id="l297" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">2</span> <span class="p">)</span> <span class="p">{</span>
</div><div id="l298" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="n">load_fixed_type</span><span class="p">();</span>
</div><div id="l299" class="code_block">	<span class="k">if</span> <span class="p">((</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l300" class="code_block">	  <span class="n">FixedPointComplex</span> <span class="n">f</span><span class="p">(</span> <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">mir</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">mdr</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">)),</span>
</div><div id="l301" class="code_block">			       <span class="n">FixedPoint</span><span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">mii</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">mdi</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">)));</span>
</div><div id="l302" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l303" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l304" class="code_block">	  <span class="n">FixedComplexMatrix</span> <span class="n">f</span> <span class="p">(</span><span class="n">FixedMatrix</span> <span class="p">(</span><span class="n">mir</span><span class="p">,</span> <span class="n">mdr</span><span class="p">),</span> 
</div><div id="l305" class="code_block">				<span class="n">FixedMatrix</span> <span class="p">(</span><span class="n">mii</span><span class="p">,</span> <span class="n">mdi</span><span class="p">));</span>
</div><div id="l306" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l307" class="code_block">	<span class="p">}</span>
</div><div id="l308" class="code_block">      <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">3</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l309" class="code_block">	<span class="n">ComplexMatrix</span> <span class="n">c</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">2</span><span class="p">).</span><span class="n">complex_matrix_value</span><span class="p">();</span>
</div><div id="l310" class="code_block">	<span class="k">if</span> <span class="p">((</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l311" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="n">load_fixed_type</span> <span class="p">();</span>
</div><div id="l312" class="code_block">	  <span class="n">FixedComplexMatrix</span> <span class="n">f</span><span class="p">(</span><span class="n">FixedMatrix</span><span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">mir</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">mdr</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> 
</div><div id="l313" class="code_block">					   <span class="n">real</span><span class="p">(</span><span class="n">c</span><span class="p">)),</span>
</div><div id="l314" class="code_block">			       <span class="n">FixedMatrix</span><span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">mii</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">mdi</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span>
</div><div id="l315" class="code_block">					   <span class="n">imag</span><span class="p">(</span><span class="n">c</span><span class="p">)));</span>
</div><div id="l316" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l317" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l318" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">mir</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">c</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">mir</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">c</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l319" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: dimension mismatch in args&quot;</span><span class="p">);</span>
</div><div id="l320" class="code_block">	  <span class="k">else</span> <span class="p">{</span>
</div><div id="l321" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="n">load_fixed_type</span> <span class="p">();</span>
</div><div id="l322" class="code_block">	    <span class="n">FixedComplexMatrix</span> <span class="n">f</span><span class="p">(</span><span class="n">FixedMatrix</span><span class="p">(</span><span class="n">mir</span><span class="p">,</span> <span class="n">mdr</span><span class="p">,</span> <span class="n">real</span><span class="p">(</span><span class="n">c</span><span class="p">)),</span>
</div><div id="l323" class="code_block">				 <span class="n">FixedMatrix</span><span class="p">(</span><span class="n">mii</span><span class="p">,</span> <span class="n">mdi</span><span class="p">,</span> <span class="n">imag</span><span class="p">(</span><span class="n">c</span><span class="p">)));</span>
</div><div id="l324" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l325" class="code_block">	  <span class="p">}</span>
</div><div id="l326" class="code_block">	<span class="p">}</span>
</div><div id="l327" class="code_block">      <span class="p">}</span>
</div><div id="l328" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l329" class="code_block">      <span class="n">MArray</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">mis</span><span class="p">,</span> <span class="n">mds</span><span class="p">;</span>
</div><div id="l330" class="code_block">      <span class="n">Matrix</span> <span class="n">a</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">matrix_value</span><span class="p">();</span>
</div><div id="l331" class="code_block">      <span class="n">Matrix</span> <span class="n">b</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">matrix_value</span><span class="p">();</span>
</div><div id="l332" class="code_block">
</div><div id="l333" class="code_block">      <span class="n">mis</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l334" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l335" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l336" class="code_block">	  <span class="n">mis</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l337" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">std</span><span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span><span class="o">-</span><span class="p">(</span><span class="kt">double</span><span class="p">)</span><span class="n">mis</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span> <span class="o">!=</span> <span class="mf">0.</span><span class="p">)</span> <span class="o">||</span> <span class="p">(</span><span class="n">mis</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l338" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: invalid fixed point representation&quot;</span><span class="p">);</span>
</div><div id="l339" class="code_block">	    <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l340" class="code_block">	  <span class="p">}</span>
</div><div id="l341" class="code_block">	<span class="p">}</span>
</div><div id="l342" class="code_block">      <span class="n">mds</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">()));</span>
</div><div id="l343" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">b</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l344" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">b</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l345" class="code_block">	  <span class="n">mds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l346" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">std</span><span class="o">::</span><span class="n">abs</span><span class="p">(</span><span class="n">b</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span><span class="o">-</span><span class="p">(</span><span class="kt">double</span><span class="p">)</span><span class="n">mds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">))</span> <span class="o">!=</span> <span class="mf">0.</span><span class="p">)</span> <span class="o">||</span> <span class="p">(</span><span class="n">mds</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l347" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: invalid fixed point representation&quot;</span><span class="p">);</span>
</div><div id="l348" class="code_block">	    <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l349" class="code_block">	  <span class="p">}</span>
</div><div id="l350" class="code_block">	<span class="p">}</span>
</div><div id="l351" class="code_block">
</div><div id="l352" class="code_block">      <span class="k">if</span> <span class="p">((</span><span class="n">mis</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mis</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span>
</div><div id="l353" class="code_block">	<span class="n">mis</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">mds</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">mds</span><span class="p">.</span><span class="n">cols</span><span class="p">()),</span><span class="n">mis</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l354" class="code_block">      <span class="k">if</span> <span class="p">((</span><span class="n">mds</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mds</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span>
</div><div id="l355" class="code_block">	<span class="n">mds</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">mis</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span><span class="n">mis</span><span class="p">.</span><span class="n">cols</span><span class="p">()),</span><span class="n">mds</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l356" class="code_block">    
</div><div id="l357" class="code_block">      <span class="k">if</span> <span class="p">((</span><span class="n">mis</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">mds</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">mis</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">mds</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l358" class="code_block">	<span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: dimension mismatch in args&quot;</span><span class="p">);</span>
</div><div id="l359" class="code_block">	<span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l360" class="code_block">      <span class="p">}</span>
</div><div id="l361" class="code_block">    
</div><div id="l362" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">2</span> <span class="p">)</span> <span class="p">{</span>
</div><div id="l363" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="n">load_fixed_type</span><span class="p">();</span>
</div><div id="l364" class="code_block">	<span class="k">if</span> <span class="p">((</span><span class="n">mis</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mis</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l365" class="code_block">	  <span class="n">FixedPoint</span> <span class="n">f</span><span class="p">(</span><span class="n">mis</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="n">mds</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l366" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l367" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l368" class="code_block">	  <span class="n">FixedMatrix</span> <span class="n">f</span><span class="p">(</span><span class="n">mis</span><span class="p">,</span> <span class="n">mds</span><span class="p">);</span>
</div><div id="l369" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l370" class="code_block">	<span class="p">}</span>
</div><div id="l371" class="code_block">      <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">3</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l372" class="code_block">	<span class="n">Matrix</span> <span class="n">a</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">2</span><span class="p">).</span><span class="n">matrix_value</span><span class="p">();</span>
</div><div id="l373" class="code_block">	<span class="k">if</span> <span class="p">((</span><span class="n">mis</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">mis</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l374" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="n">load_fixed_type</span> <span class="p">();</span>
</div><div id="l375" class="code_block">	  <span class="n">FixedMatrix</span> <span class="n">f</span> <span class="p">(</span><span class="n">mis</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="n">mds</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="n">a</span><span class="p">);</span>
</div><div id="l376" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l377" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l378" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">mis</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">mis</span><span class="p">.</span><span class="n">cols</span><span class="p">()</span> <span class="o">!=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">()))</span>
</div><div id="l379" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: dimension mismatch in args&quot;</span><span class="p">);</span>
</div><div id="l380" class="code_block">	  <span class="k">else</span> <span class="p">{</span>
</div><div id="l381" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="n">load_fixed_type</span> <span class="p">();</span>
</div><div id="l382" class="code_block">	    <span class="n">FixedMatrix</span> <span class="n">f</span> <span class="p">(</span><span class="n">mis</span><span class="p">,</span> <span class="n">mds</span><span class="p">,</span> <span class="n">a</span><span class="p">);</span>
</div><div id="l383" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l384" class="code_block">	  <span class="p">}</span>
</div><div id="l385" class="code_block">	<span class="p">}</span>
</div><div id="l386" class="code_block">      <span class="p">}</span>
</div><div id="l387" class="code_block">    <span class="p">}</span>
</div><div id="l388" class="code_block">  <span class="p">}</span> <span class="k">else</span>
</div><div id="l389" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l390" class="code_block">  
</div><div id="l391" class="code_block">  
</div><div id="l392" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l393" class="code_block">    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fixed: failed to create fixed point number&quot;</span><span class="p">);</span>
</div><div id="l394" class="code_block">    <span class="k">return</span> <span class="n">octave_value</span><span class="p">();</span>
</div><div id="l395" class="code_block">  <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l396" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">maybe_mutate</span><span class="p">();</span>
</div><div id="l397" class="code_block">    <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l398" class="code_block">  <span class="p">}</span>
</div><div id="l399" class="code_block"><span class="p">}</span>
</div><div id="l400" class="code_block">
</div><div id="l401" class="code_block"><span class="c1">// This macro must start with DEFUN_DLD so that the automatic collection</span>
</div><div id="l402" class="code_block"><span class="c1">// of the function helps can take place!! The second DEFUN_DLD must NOT</span>
</div><div id="l403" class="code_block"><span class="c1">// appear on a new-line, otherwise the indexing script will be confused!!</span>
</div><div id="l404" class="code_block"><span class="cp">#define DEFUN_DLD_FIXED_SNGL_ARG(NAME, HELP, FUNC, \</span>
</div><div id="l405" class="code_block"><span class="cp">   REAL_CAN_RET_CMPLX_UPPER,UPPER, REAL_CAN_RET_CMPLX_LOWER, \</span>
</div><div id="l406" class="code_block"><span class="cp">   LOWER) DEFUN_DLD (NAME, args, nargout, HELP) \</span>
</div><div id="l407" class="code_block"><span class="cp">  { \</span>
</div><div id="l408" class="code_block"><span class="cp">    int nargin = args.length(); \</span>
</div><div id="l409" class="code_block"><span class="cp">    octave_value retval; \</span>
</div><div id="l410" class="code_block"><span class="cp">    if ( nargin != 1 ) { \</span>
</div><div id="l411" class="code_block"><span class="cp">      print_usage (); \</span>
</div><div id="l412" class="code_block"><span class="cp">    } else { \</span>
</div><div id="l413" class="code_block"><span class="cp">      if (fixed_type_loaded) { \</span>
</div><div id="l414" class="code_block"><span class="cp">        if (args(0).type_id () == octave_fixed::static_type_id ()) { \</span>
</div><div id="l415" class="code_block"><span class="cp">	  FixedPoint f = ((const octave_fixed&amp;) args(0).get_rep()) \</span>
</div><div id="l416" class="code_block"><span class="cp">	    .fixed_value (); \</span>
</div><div id="l417" class="code_block"><span class="cp">          if ((REAL_CAN_RET_CMPLX_UPPER &amp;&amp; (f &gt; UPPER)) || \</span>
</div><div id="l418" class="code_block"><span class="cp">              (REAL_CAN_RET_CMPLX_LOWER &amp;&amp; (f &lt; LOWER))) \</span>
</div><div id="l419" class="code_block"><span class="cp">	    retval = new octave_fixed_complex \</span>
</div><div id="l420" class="code_block"><span class="cp">                    (FUNC (FixedPointComplex(f,FixedPoint(f.getintsize(), \</span>
</div><div id="l421" class="code_block"><span class="cp">						f.getdecsize())))); \</span>
</div><div id="l422" class="code_block"><span class="cp">          else \</span>
</div><div id="l423" class="code_block"><span class="cp">	    retval = new octave_fixed (FUNC (f)); \</span>
</div><div id="l424" class="code_block"><span class="cp">        } else if (args(0).type_id () == \</span>
</div><div id="l425" class="code_block"><span class="cp">				octave_fixed_matrix::static_type_id ()) { \</span>
</div><div id="l426" class="code_block"><span class="cp">	  FixedMatrix f = ((const octave_fixed_matrix&amp;) args(0).get_rep()) \</span>
</div><div id="l427" class="code_block"><span class="cp">	    .fixed_matrix_value (); \</span>
</div><div id="l428" class="code_block"><span class="cp">          if ((REAL_CAN_RET_CMPLX_UPPER &amp;&amp; (f.row_max().max() \</span>
</div><div id="l429" class="code_block"><span class="cp">							&gt; UPPER)) || \</span>
</div><div id="l430" class="code_block"><span class="cp">              (REAL_CAN_RET_CMPLX_LOWER &amp;&amp; (f.row_min().min() \</span>
</div><div id="l431" class="code_block"><span class="cp">							&lt; LOWER))) { \</span>
</div><div id="l432" class="code_block"><span class="cp">             retval = new octave_fixed_complex_matrix \</span>
</div><div id="l433" class="code_block"><span class="cp">                     (FUNC (FixedComplexMatrix(f))); \</span>
</div><div id="l434" class="code_block"><span class="cp">          } else \</span>
</div><div id="l435" class="code_block"><span class="cp">	    retval = new octave_fixed_matrix (FUNC (f)); \</span>
</div><div id="l436" class="code_block"><span class="cp">        } else if (args(0).type_id () == \</span>
</div><div id="l437" class="code_block"><span class="cp">		   octave_fixed_complex::static_type_id ()) { \</span>
</div><div id="l438" class="code_block"><span class="cp">	  FixedPointComplex f = ((const octave_fixed_complex&amp;) \</span>
</div><div id="l439" class="code_block"><span class="cp">                   args(0).get_rep()).fixed_complex_value (); \</span>
</div><div id="l440" class="code_block"><span class="cp">          retval = new octave_fixed_complex (FUNC (f)); \</span>
</div><div id="l441" class="code_block"><span class="cp">        } else if (args(0).type_id () == \</span>
</div><div id="l442" class="code_block"><span class="cp">		   octave_fixed_complex_matrix::static_type_id ()) { \</span>
</div><div id="l443" class="code_block"><span class="cp">	  FixedComplexMatrix f = ((const octave_fixed_complex_matrix&amp;) \</span>
</div><div id="l444" class="code_block"><span class="cp">                   args(0).get_rep()).fixed_complex_matrix_value (); \</span>
</div><div id="l445" class="code_block"><span class="cp">          retval = new octave_fixed_complex_matrix (FUNC (f)); \</span>
</div><div id="l446" class="code_block"><span class="cp">        } else \</span>
</div><div id="l447" class="code_block"><span class="cp">	  print_usage (); \</span>
</div><div id="l448" class="code_block"><span class="cp">      } else \</span>
</div><div id="l449" class="code_block"><span class="cp">        print_usage (); \</span>
</div><div id="l450" class="code_block"><span class="cp">    } \</span>
</div><div id="l451" class="code_block"><span class="cp">    retval.maybe_mutate(); \</span>
</div><div id="l452" class="code_block"><span class="cp">    return retval; \</span>
</div><div id="l453" class="code_block"><span class="cp">  }</span>
</div><div id="l454" class="code_block">
</div><div id="l455" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;freal&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l456" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;real&quot;, &quot;freal&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l457" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;real&quot;, &quot;freal&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l458" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;real&quot;, &quot;freal&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l459" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;real&quot;, &quot;freal&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l460" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">freal</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l461" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} freal (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l462" class="code_block"><span class="s">Returns the real part of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l463" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">real</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l464" class="code_block">
</div><div id="l465" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fimag&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l466" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;imag&quot;, &quot;fimag&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l467" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;imag&quot;, &quot;fimag&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l468" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;imag&quot;, &quot;fimag&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l469" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;imag&quot;, &quot;fimag&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l470" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fimag</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l471" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fimag (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l472" class="code_block"><span class="s">Returns the imaginary part of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l473" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">imag</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l474" class="code_block">
</div><div id="l475" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fconj&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l476" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;conj&quot;, &quot;fconj&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l477" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;conj&quot;, &quot;fconj&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l478" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;conj&quot;, &quot;fconj&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l479" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;conj&quot;, &quot;fconj&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l480" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fconj</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l481" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fconj (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l482" class="code_block"><span class="s">Returns the conjuate of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l483" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">conj</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l484" class="code_block">
</div><div id="l485" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fabs&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l486" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;abs&quot;, &quot;fabs&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l487" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;abs&quot;, &quot;fabs&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l488" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;abs&quot;, &quot;fabs&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l489" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;abs&quot;, &quot;fabs&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l490" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fabs</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l491" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fabs (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l492" class="code_block"><span class="s">Compute the magnitude of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l493" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">abs</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l494" class="code_block">
</div><div id="l495" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;farg&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l496" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;arg&quot;, &quot;farg&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l497" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;arg&quot;, &quot;farg&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l498" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;arg&quot;, &quot;farg&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l499" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;arg&quot;, &quot;farg&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l500" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">farg</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l501" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} farg (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l502" class="code_block"><span class="s">Compute the argument of @var{x}, defined as</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l503" class="code_block"><span class="s">@iftex</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l504" class="code_block"><span class="s">@tex</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l505" class="code_block"><span class="s">$</span><span class="se">\\</span><span class="s">theta = atan2( y , x)$</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l506" class="code_block"><span class="s">@end tex</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l507" class="code_block"><span class="s">@end iftex</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l508" class="code_block"><span class="s">@ifinfo</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l509" class="code_block"><span class="s">@var{theta} = @code{atan2 (@var{y}, @var{x})}</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l510" class="code_block"><span class="s">@end ifinfo</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l511" class="code_block"><span class="s">in radians. For example</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l512" class="code_block"><span class="se">\n</span><span class="s">\</span>
</div><div id="l513" class="code_block"><span class="s">@example</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l514" class="code_block"><span class="s">@group</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l515" class="code_block"><span class="s">farg (fixed (3,5,3+4i))</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l516" class="code_block"><span class="s">      @result{}  0.90625</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l517" class="code_block"><span class="s">@end group</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l518" class="code_block"><span class="s">@end example</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l519" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">arg</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="mi">0</span><span class="p">,</span><span class="mi">1</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">())</span>
</div><div id="l520" class="code_block">
</div><div id="l521" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fangle&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l522" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;angle&quot;, &quot;fangle&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l523" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;angle&quot;, &quot;fangle&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l524" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;angle&quot;, &quot;fangle&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l525" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;angle&quot;, &quot;fangle&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l526" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fangle</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l527" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fangle (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l528" class="code_block"><span class="s">See @dfn{farg}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l529" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">arg</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="mi">0</span><span class="p">,</span><span class="mi">1</span><span class="p">,</span><span class="mi">0</span><span class="p">),</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">())</span>
</div><div id="l530" class="code_block">
</div><div id="l531" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fcos&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l532" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cos&quot;, &quot;fcos&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l533" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cos&quot;, &quot;fcos&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l534" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cos&quot;, &quot;fcos&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l535" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cos&quot;, &quot;fcos&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l536" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fcos</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l537" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fcos (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l538" class="code_block"><span class="s">Compute the cosine of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l539" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l540" class="code_block"><span class="s">@seealso{fcosh, fsin, fsinh, ftan, ftanh}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">cos</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l541" class="code_block">
</div><div id="l542" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fcosh&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l543" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cosh&quot;, &quot;fcosh&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l544" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cosh&quot;, &quot;fcosh&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l545" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cosh&quot;, &quot;fcosh&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l546" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cosh&quot;, &quot;fcosh&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l547" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fcosh</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l548" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fcosh (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l549" class="code_block"><span class="s">Compute the hyperbolic cosine of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l550" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l551" class="code_block"><span class="s">@seealso{fcos, fsin, fsinh, ftan, ftanh}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">cosh</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l552" class="code_block">
</div><div id="l553" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fsin&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l554" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sin&quot;, &quot;fsin&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l555" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sin&quot;, &quot;fsin&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l556" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sin&quot;, &quot;fsin&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l557" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sin&quot;, &quot;fsin&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l558" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fsin</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l559" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fsin (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l560" class="code_block"><span class="s">Compute the sine of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l561" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l562" class="code_block"><span class="s">@seealso{fcos, fcosh, fsinh, ftan, ftanh}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">sin</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l563" class="code_block">
</div><div id="l564" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fsinh&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l565" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sinh&quot;, &quot;fsinh&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l566" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sinh&quot;, &quot;fsinh&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l567" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sinh&quot;, &quot;fsinh&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l568" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sinh&quot;, &quot;fsinh&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l569" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fsinh</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l570" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fsinh (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l571" class="code_block"><span class="s">Compute the hyperbolic sine of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l572" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l573" class="code_block"><span class="s">@seealso{fcos, fcosh, fsin, ftan, ftanh}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">sinh</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l574" class="code_block">
</div><div id="l575" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;ftan&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l576" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tan&quot;, &quot;ftan&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l577" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tan&quot;, &quot;ftan&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l578" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tan&quot;, &quot;ftan&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l579" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tan&quot;, &quot;ftan&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l580" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">ftan</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l581" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} ftan (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l582" class="code_block"><span class="s">Compute the tan of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l583" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l584" class="code_block"><span class="s">@seealso{fcos, fcosh, fsinh, ftan, ftanh}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">tan</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l585" class="code_block">
</div><div id="l586" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;ftanh&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l587" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tanh&quot;, &quot;ftanh&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l588" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tanh&quot;, &quot;ftanh&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l589" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tanh&quot;, &quot;ftanh&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l590" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;tanh&quot;, &quot;ftanh&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l591" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">ftanh</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l592" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} ftanh (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l593" class="code_block"><span class="s">Compute the hyperbolic tan of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l594" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l595" class="code_block"><span class="s">@seealso{fcos, fcosh, fsin, fsinh, ftan}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">tanh</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l596" class="code_block">
</div><div id="l597" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fsqrt&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l598" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sqrt&quot;, &quot;fsqrt&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l599" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sqrt&quot;, &quot;fsqrt&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l600" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sqrt&quot;, &quot;fsqrt&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l601" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sqrt&quot;, &quot;fsqrt&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l602" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fsqrt</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l603" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fsqrt (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l604" class="code_block"><span class="s">Compute the square-root of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l605" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">sqrt</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">());</span>
</div><div id="l606" class="code_block">
</div><div id="l607" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fexp&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l608" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;exp&quot;, &quot;fexp&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l609" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;exp&quot;, &quot;fexp&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l610" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;exp&quot;, &quot;fexp&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l611" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;exp&quot;, &quot;fexp&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l612" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fexp</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l613" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fexp (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l614" class="code_block"><span class="s">Compute the exponential of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l615" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l616" class="code_block"><span class="s">@seealso{log, log10, pow}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">exp</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l617" class="code_block">
</div><div id="l618" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;flog&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l619" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log&quot;, &quot;flog&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l620" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log&quot;, &quot;flog&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l621" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log&quot;, &quot;flog&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l622" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log&quot;, &quot;flog&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l623" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">flog</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l624" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} flog (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l625" class="code_block"><span class="s">Compute the natural logarithm of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l626" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l627" class="code_block"><span class="s">@seealso{fexp, flog10, fpow}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">log</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">());</span>
</div><div id="l628" class="code_block">
</div><div id="l629" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;flog10&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l630" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log10&quot;, &quot;flog10&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l631" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log10&quot;, &quot;flog10&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l632" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log10&quot;, &quot;flog10&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l633" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;log10&quot;, &quot;flog10&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l634" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">flog10</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l635" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} flog10 (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l636" class="code_block"><span class="s">Compute the base-10 logarithm of the fixed point value @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l637" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l638" class="code_block"><span class="s">@seealso{fexp, flog, fpow}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">log10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">());</span>
</div><div id="l639" class="code_block">
</div><div id="l640" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fround&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l641" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;round&quot;, &quot;fround&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l642" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;round&quot;, &quot;fround&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l643" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;round&quot;, &quot;fround&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l644" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;round&quot;, &quot;fround&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l645" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fround</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l646" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fround (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l647" class="code_block"><span class="s">Return the rounded value to the nearest integer of @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l648" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l649" class="code_block"><span class="s">@seealso{ffloor, fceil}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">round</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l650" class="code_block">
</div><div id="l651" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;ffloor&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l652" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;floor&quot;, &quot;ffloor&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l653" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;floor&quot;, &quot;ffloor&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l654" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;floor&quot;, &quot;ffloor&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l655" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;floor&quot;, &quot;ffloor&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l656" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">ffloor</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l657" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} ffloor (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l658" class="code_block"><span class="s">Return the largest integer not greater than @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l659" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l660" class="code_block"><span class="s">@seealso{fround, fceil}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">floor</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l661" class="code_block">
</div><div id="l662" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fceil&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l663" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;ceil&quot;, &quot;fceil&quot;, &quot;fixed scalar&quot;)</span>
</div><div id="l664" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;ceil&quot;, &quot;fceil&quot;, &quot;fixed matrix&quot;)</span>
</div><div id="l665" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;ceil&quot;, &quot;fceil&quot;, &quot;fixed complex&quot;)</span>
</div><div id="l666" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;ceil&quot;, &quot;fceil&quot;, &quot;fixed complex matrix&quot;)</span>
</div><div id="l667" class="code_block"><span class="n">DEFUN_DLD_FIXED_SNGL_ARG</span> <span class="p">(</span><span class="n">fceil</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l668" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fceil (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l669" class="code_block"><span class="s">Return the smallest integer not less than @var{x}.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l670" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l671" class="code_block"><span class="s">@seealso{fround, ffloor}&quot;</span><span class="p">,</span> <span class="o">::</span><span class="n">ceil</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l672" class="code_block">
</div><div id="l673" class="code_block"><span class="c1">// This macro must start with DEFUN_DLD so that the automatic collection</span>
</div><div id="l674" class="code_block"><span class="c1">// of the function helps can take place!! The second DEFUN_DLD must NOT</span>
</div><div id="l675" class="code_block"><span class="c1">// appear on a new-line, otherwise the indexing script will be confused!!</span>
</div><div id="l676" class="code_block"><span class="cp">#define DEFUN_DLD_FIXED_DIM_ARG(NAME, HELP, FUNC) DEFUN_DLD (NAME, args, nargout, HELP) \</span>
</div><div id="l677" class="code_block"><span class="cp">  { \</span>
</div><div id="l678" class="code_block"><span class="cp">    int nargin = args.length(); \</span>
</div><div id="l679" class="code_block"><span class="cp">    octave_value retval; \</span>
</div><div id="l680" class="code_block"><span class="cp">    if ((nargin != 1 ) &amp;&amp; (nargin != 2)) \</span>
</div><div id="l681" class="code_block"><span class="cp">      print_usage (); \</span>
</div><div id="l682" class="code_block"><span class="cp">    else { \</span>
</div><div id="l683" class="code_block"><span class="cp">      int dim = (nargin == 1 ? -1 : args(1).int_value(true) - 1); \</span>
</div><div id="l684" class="code_block"><span class="cp">      if (error_state) return retval; \</span>
</div><div id="l685" class="code_block"><span class="cp">      if (dim &lt; -1 || dim &gt; 1) { \</span>
</div><div id="l686" class="code_block"><span class="cp">	error (#NAME &quot;: invalid dimension argument = %d&quot;, dim + 1); \</span>
</div><div id="l687" class="code_block"><span class="cp">        return retval; \</span>
</div><div id="l688" class="code_block"><span class="cp">      } \</span>
</div><div id="l689" class="code_block"><span class="cp">      if (fixed_type_loaded) { \</span>
</div><div id="l690" class="code_block"><span class="cp">        if (args(0).type_id () == octave_fixed::static_type_id ()) { \</span>
</div><div id="l691" class="code_block"><span class="cp">	    FixedMatrix f = ((const octave_fixed&amp;) args(0).get_rep()) \</span>
</div><div id="l692" class="code_block"><span class="cp">	      .fixed_matrix_value (); \</span>
</div><div id="l693" class="code_block"><span class="cp">            retval  = new octave_fixed( f .FUNC (dim) (0,0)); \</span>
</div><div id="l694" class="code_block"><span class="cp">        } else if (args(0).type_id () == octave_fixed_complex:: \</span>
</div><div id="l695" class="code_block"><span class="cp">		 static_type_id ()) { \</span>
</div><div id="l696" class="code_block"><span class="cp">	    FixedComplexMatrix f = ((const octave_fixed_complex&amp;) \</span>
</div><div id="l697" class="code_block"><span class="cp">	      args(0).get_rep()).fixed_complex_matrix_value (); \</span>
</div><div id="l698" class="code_block"><span class="cp">            retval = new octave_fixed_complex(f .FUNC (dim) (0,0)); \</span>
</div><div id="l699" class="code_block"><span class="cp">        } else if (args(0).type_id () == \</span>
</div><div id="l700" class="code_block"><span class="cp">		   octave_fixed_matrix::static_type_id ()) { \</span>
</div><div id="l701" class="code_block"><span class="cp">	    FixedMatrix f = ((const octave_fixed_matrix&amp;) args(0).get_rep()) \</span>
</div><div id="l702" class="code_block"><span class="cp">	      .fixed_matrix_value (); \</span>
</div><div id="l703" class="code_block"><span class="cp">            retval = new octave_fixed_matrix(f .FUNC (dim)); \</span>
</div><div id="l704" class="code_block"><span class="cp">        } else if (args(0).type_id () == \</span>
</div><div id="l705" class="code_block"><span class="cp">		   octave_fixed_complex_matrix::static_type_id ()) { \</span>
</div><div id="l706" class="code_block"><span class="cp">	    FixedComplexMatrix f = ((const octave_fixed_complex_matrix&amp;) \</span>
</div><div id="l707" class="code_block"><span class="cp">	      args(0).get_rep()).fixed_complex_matrix_value (); \</span>
</div><div id="l708" class="code_block"><span class="cp">            retval = new octave_fixed_complex_matrix(f .FUNC (dim)); \</span>
</div><div id="l709" class="code_block"><span class="cp">        } else \</span>
</div><div id="l710" class="code_block"><span class="cp">	    print_usage (); \</span>
</div><div id="l711" class="code_block"><span class="cp">      } else \</span>
</div><div id="l712" class="code_block"><span class="cp">        print_usage (); \</span>
</div><div id="l713" class="code_block"><span class="cp">    } \</span>
</div><div id="l714" class="code_block"><span class="cp">    retval.maybe_mutate(); \</span>
</div><div id="l715" class="code_block"><span class="cp">    return retval; \</span>
</div><div id="l716" class="code_block"><span class="cp">  }</span>
</div><div id="l717" class="code_block">
</div><div id="l718" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fprod&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l719" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;prod&quot;, &quot;fprod&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l720" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;prod&quot;, &quot;fprod&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l721" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;prod&quot;, &quot;fprod&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l722" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;prod&quot;, &quot;fprod&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l723" class="code_block"><span class="n">DEFUN_DLD_FIXED_DIM_ARG</span> <span class="p">(</span><span class="n">fprod</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l724" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fprod (@var{x},@var{dim})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l725" class="code_block"><span class="s">Product of elements along dimension @var{dim}.  If @var{dim} is omitted,</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l726" class="code_block"><span class="s">it defaults to 1 (column-wise products).</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l727" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l728" class="code_block"><span class="s">@seealso{fsum, fsumsq}&quot;</span><span class="p">,</span> <span class="n">prod</span><span class="p">)</span>
</div><div id="l729" class="code_block">
</div><div id="l730" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fcumprod&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l731" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumprod&quot;, &quot;fcumprod&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l732" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumprod&quot;, &quot;fcumprod&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l733" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumprod&quot;, &quot;fcumprod&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l734" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumprod&quot;, &quot;fcumprod&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l735" class="code_block"><span class="n">DEFUN_DLD_FIXED_DIM_ARG</span> <span class="p">(</span><span class="n">fcumprod</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l736" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fcumprod (@var{x},@var{dim})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l737" class="code_block"><span class="s">Cumulative product of elements along dimension @var{dim}.  If @var{dim}</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l738" class="code_block"><span class="s">is omitted, it defaults to 1 (column-wise cumulative products).</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l739" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l740" class="code_block"><span class="s">@seealso{fcumsum}&quot;</span><span class="p">,</span> <span class="n">cumprod</span><span class="p">)</span>
</div><div id="l741" class="code_block">
</div><div id="l742" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fsum&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l743" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sum&quot;, &quot;fsum&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l744" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sum&quot;, &quot;fsum&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l745" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sum&quot;, &quot;fsum&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l746" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sum&quot;, &quot;fsum&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l747" class="code_block"><span class="n">DEFUN_DLD_FIXED_DIM_ARG</span> <span class="p">(</span><span class="n">fsum</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l748" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fsum (@var{x},@var{dim})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l749" class="code_block"><span class="s">Sum of elements along dimension @var{dim}.  If @var{dim} is omitted, it</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l750" class="code_block"><span class="s">defaults to 1 (column-wise sum).</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l751" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l752" class="code_block"><span class="s">@seealso{fprod, fsumsq}&quot;</span><span class="p">,</span> <span class="n">sum</span><span class="p">)</span>
</div><div id="l753" class="code_block">
</div><div id="l754" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fcumsum&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l755" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumsum&quot;, &quot;fcumsum&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l756" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumsum&quot;, &quot;fcumsum&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l757" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumsum&quot;, &quot;fcumsum&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l758" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;cumsum&quot;, &quot;fcumsum&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l759" class="code_block"><span class="n">DEFUN_DLD_FIXED_DIM_ARG</span> <span class="p">(</span><span class="n">fcumsum</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l760" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fcumsum (@var{x},@var{dim})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l761" class="code_block"><span class="s">Cumulative sum of elements along dimension @var{dim}.  If @var{dim}</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l762" class="code_block"><span class="s">is omitted, it defaults to 1 (column-wise cumulative sums).</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l763" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l764" class="code_block"><span class="s">@seealso{fcumprod}&quot;</span><span class="p">,</span> <span class="n">cumsum</span><span class="p">)</span>
</div><div id="l765" class="code_block">
</div><div id="l766" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fsumsq&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l767" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sumsq&quot;, &quot;fsumsq&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l768" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sumsq&quot;, &quot;fsumsq&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l769" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sumsq&quot;, &quot;fsumsq&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l770" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;sumsq&quot;, &quot;fsumsq&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l771" class="code_block"><span class="n">DEFUN_DLD_FIXED_DIM_ARG</span> <span class="p">(</span><span class="n">fsumsq</span><span class="p">,</span> <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l772" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =} fsumsq (@var{x},@var{dim})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l773" class="code_block"><span class="s">Sum of squares of elements along dimension @var{dim}.  If @var{dim}</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l774" class="code_block"><span class="s">is omitted, it defaults to 1 (column-wise sum of squares).</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l775" class="code_block"><span class="s">This function is equivalent to computing</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l776" class="code_block"><span class="s">@example</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l777" class="code_block"><span class="s">fsum (x .* fconj (x), dim)</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l778" class="code_block"><span class="s">@end example</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l779" class="code_block"><span class="s">but it uses less memory and avoids calling @code{fconj} if @var{x} is real.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l780" class="code_block"><span class="s">@end deftypefn</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l781" class="code_block"><span class="s">@seealso{fprod, fsum}&quot;</span><span class="p">,</span> <span class="n">sumsq</span><span class="p">)</span>
</div><div id="l782" class="code_block">
</div><div id="l783" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;freshape&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l784" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;reshape&quot;, &quot;freshape&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l785" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;reshape&quot;, &quot;freshape&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l786" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;reshape&quot;, &quot;freshape&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l787" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;reshape&quot;, &quot;freshape&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l788" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">freshape</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l789" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l790" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {} freshape (@var{a}, @var{m}, @var{n})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l791" class="code_block"><span class="s">&quot;Return a fixed matrix with @var{m} rows and @var{n} columns whose elements</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l792" class="code_block"><span class="s">&quot;are taken from the fixed matrix @var{a}.  To decide how to order the</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l793" class="code_block"><span class="s">&quot;elements, Octave pretends that the elements of a matrix are stored in</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l794" class="code_block"><span class="s">&quot;column-major order (like Fortran arrays are stored).</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l795" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l796" class="code_block"><span class="s">&quot;For example,</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l797" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l798" class="code_block"><span class="s">&quot;@example</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l799" class="code_block"><span class="s">&quot;freshape (fixed(3, 2, [1, 2, 3, 4]), 2, 2)</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l800" class="code_block"><span class="s">&quot;ans =</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l801" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l802" class="code_block"><span class="s">&quot;  1.00  3.00</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l803" class="code_block"><span class="s">&quot;  2.00  4.00</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l804" class="code_block"><span class="s">&quot;@end example</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l805" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l806" class="code_block"><span class="s">&quot;If the variable @code{do_fortran_indexing} is nonzero, the</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l807" class="code_block"><span class="s">&quot;@code{freshape} function is equivalent to</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l808" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l809" class="code_block"><span class="s">&quot;@example</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l810" class="code_block"><span class="s">&quot;@group</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l811" class="code_block"><span class="s">&quot;retval = fixed(0,0,zeros (m, n));</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l812" class="code_block"><span class="s">&quot;retval (:) = a;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l813" class="code_block"><span class="s">&quot;@end group</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l814" class="code_block"><span class="s">&quot;@end example</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l815" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l816" class="code_block"><span class="s">&quot;@noindent</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l817" class="code_block"><span class="s">&quot;but it is somewhat less cryptic to use @code{freshape} instead of the</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l818" class="code_block"><span class="s">&quot;colon operator.  Note that the total number of elements in the original</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l819" class="code_block"><span class="s">&quot;matrix must match the total number of elements in the new matrix.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l820" class="code_block"><span class="s">&quot;@end deftypefn</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l821" class="code_block"><span class="s">&quot;@seealso{`:&#39; and do_fortran_indexing}&quot;</span><span class="p">)</span> 
</div><div id="l822" class="code_block"><span class="p">{</span>
</div><div id="l823" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l824" class="code_block">  <span class="kt">int</span> <span class="n">nargin</span> <span class="o">=</span> <span class="n">args</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l825" class="code_block">
</div><div id="l826" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">!=</span> <span class="mi">2</span> <span class="o">&amp;&amp;</span> <span class="n">nargin</span> <span class="o">!=</span><span class="mi">3</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l827" class="code_block">    <span class="n">error</span><span class="p">(</span><span class="s">&quot;freshape (a, m, m) or freshape (a, size(b))&quot;</span><span class="p">);</span>
</div><div id="l828" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l829" class="code_block">  <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l830" class="code_block">    <span class="kt">int</span> <span class="n">mr</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">mc</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l831" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l832" class="code_block">      <span class="n">RowVector</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">row_vector_value</span><span class="p">();</span>
</div><div id="l833" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">tmp</span><span class="p">.</span><span class="n">length</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">2</span><span class="p">)</span>
</div><div id="l834" class="code_block">	<span class="n">error</span><span class="p">(</span><span class="s">&quot;freshape: called with 2 args, second must be 2-element vector&quot;</span><span class="p">);</span> 
</div><div id="l835" class="code_block">      <span class="n">mr</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">tmp</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l836" class="code_block">      <span class="n">mc</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">tmp</span><span class="p">(</span><span class="mi">1</span><span class="p">);</span>
</div><div id="l837" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">3</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l838" class="code_block">      <span class="n">mr</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">nint_value</span> <span class="p">();</span>
</div><div id="l839" class="code_block">      <span class="n">mc</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">2</span><span class="p">).</span><span class="n">nint_value</span> <span class="p">();</span>
</div><div id="l840" class="code_block">    <span class="p">}</span> 
</div><div id="l841" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_scalar_type</span><span class="p">())</span>
</div><div id="l842" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">mr</span> <span class="o">!=</span> <span class="mi">1</span> <span class="o">||</span> <span class="n">mc</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l843" class="code_block">	<span class="n">error</span><span class="p">(</span><span class="s">&quot;freshape: sizes must match&quot;</span><span class="p">);</span>
</div><div id="l844" class="code_block">      <span class="k">else</span>
</div><div id="l845" class="code_block">	<span class="n">retval</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l846" class="code_block">    <span class="k">else</span> <span class="p">{</span>
</div><div id="l847" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_complex_type</span><span class="p">())</span> <span class="p">{</span>
</div><div id="l848" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span> <span class="o">&amp;&amp;</span>
</div><div id="l849" class="code_block">	    <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l850" class="code_block">	       <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l851" class="code_block">	  <span class="n">FixedComplexMatrix</span> <span class="n">a</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span> 
</div><div id="l852" class="code_block">			<span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l853" class="code_block">	  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span>
</div><div id="l854" class="code_block">	  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span>
</div><div id="l855" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">nr</span> <span class="o">*</span> <span class="n">nc</span><span class="p">)</span> <span class="o">!=</span> <span class="p">(</span><span class="n">mr</span> <span class="o">*</span> <span class="n">mc</span><span class="p">))</span>
</div><div id="l856" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;freshape: sizes must match&quot;</span><span class="p">);</span>
</div><div id="l857" class="code_block">	  <span class="k">else</span> <span class="p">{</span>
</div><div id="l858" class="code_block">	    <span class="n">FixedComplexRowVector</span> <span class="n">tmp1</span><span class="p">(</span><span class="n">mr</span><span class="o">*</span><span class="n">mc</span><span class="p">);</span>
</div><div id="l859" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">i</span><span class="o">&lt;</span><span class="n">nr</span><span class="p">;</span><span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l860" class="code_block">	      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">j</span><span class="o">&lt;</span><span class="n">nc</span><span class="p">;</span><span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l861" class="code_block">		<span class="n">tmp1</span><span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">j</span><span class="o">*</span><span class="n">nr</span><span class="p">)</span> <span class="o">=</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l862" class="code_block">	    <span class="n">FixedComplexMatrix</span> <span class="n">tmp2</span><span class="p">(</span><span class="n">mr</span><span class="p">,</span><span class="n">mc</span><span class="p">);</span>
</div><div id="l863" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">i</span><span class="o">&lt;</span><span class="n">mr</span><span class="p">;</span><span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l864" class="code_block">	      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">j</span><span class="o">&lt;</span><span class="n">mc</span><span class="p">;</span><span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l865" class="code_block">		<span class="n">tmp2</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp1</span><span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">j</span><span class="o">*</span><span class="n">mr</span><span class="p">);</span>
</div><div id="l866" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span><span class="p">(</span><span class="n">tmp2</span><span class="p">);</span>
</div><div id="l867" class="code_block">	  <span class="p">}</span>
</div><div id="l868" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l869" class="code_block">	  <span class="n">gripe_wrong_type_arg</span> <span class="p">(</span><span class="s">&quot;freshape&quot;</span><span class="p">,</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l870" class="code_block">	  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l871" class="code_block">	<span class="p">}</span>
</div><div id="l872" class="code_block">      <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l873" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span> <span class="o">&amp;&amp;</span>
</div><div id="l874" class="code_block">	    <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l875" class="code_block">	  <span class="n">FixedMatrix</span> <span class="n">a</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span>
</div><div id="l876" class="code_block">	    <span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l877" class="code_block">	  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span>
</div><div id="l878" class="code_block">	  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">a</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span>
</div><div id="l879" class="code_block">	  <span class="k">if</span> <span class="p">((</span><span class="n">nr</span> <span class="o">*</span> <span class="n">nc</span><span class="p">)</span> <span class="o">!=</span> <span class="p">(</span><span class="n">mr</span> <span class="o">*</span> <span class="n">mc</span><span class="p">))</span>
</div><div id="l880" class="code_block">	    <span class="n">error</span><span class="p">(</span><span class="s">&quot;freshape: sizes must match&quot;</span><span class="p">);</span>
</div><div id="l881" class="code_block">	  <span class="k">else</span> <span class="p">{</span>
</div><div id="l882" class="code_block">	    <span class="n">FixedRowVector</span> <span class="n">tmp1</span><span class="p">(</span><span class="n">mr</span><span class="o">*</span><span class="n">mc</span><span class="p">);</span>
</div><div id="l883" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">i</span><span class="o">&lt;</span><span class="n">nr</span><span class="p">;</span><span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l884" class="code_block">	      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">j</span><span class="o">&lt;</span><span class="n">nc</span><span class="p">;</span><span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l885" class="code_block">		<span class="n">tmp1</span><span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">j</span><span class="o">*</span><span class="n">nr</span><span class="p">)</span> <span class="o">=</span> <span class="n">a</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">);</span>
</div><div id="l886" class="code_block">	    <span class="n">FixedMatrix</span> <span class="n">tmp2</span><span class="p">(</span><span class="n">mr</span><span class="p">,</span><span class="n">mc</span><span class="p">);</span>
</div><div id="l887" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">i</span><span class="o">&lt;</span><span class="n">mr</span><span class="p">;</span><span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l888" class="code_block">	      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span><span class="n">j</span><span class="o">&lt;</span><span class="n">mc</span><span class="p">;</span><span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l889" class="code_block">		<span class="n">tmp2</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">tmp1</span><span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">j</span><span class="o">*</span><span class="n">mr</span><span class="p">);</span>
</div><div id="l890" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span><span class="p">(</span><span class="n">tmp2</span><span class="p">);</span>
</div><div id="l891" class="code_block">	  <span class="p">}</span>
</div><div id="l892" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l893" class="code_block">	  <span class="n">gripe_wrong_type_arg</span> <span class="p">(</span><span class="s">&quot;freshape&quot;</span><span class="p">,</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l894" class="code_block">	  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l895" class="code_block">	<span class="p">}</span>
</div><div id="l896" class="code_block">      <span class="p">}</span>
</div><div id="l897" class="code_block">    <span class="p">}</span>
</div><div id="l898" class="code_block">  <span class="p">}</span>
</div><div id="l899" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l900" class="code_block"><span class="p">}</span>
</div><div id="l901" class="code_block">
</div><div id="l902" class="code_block"><span class="k">static</span> <span class="n">octave_value</span>
</div><div id="l903" class="code_block"><span class="n">make_fdiag</span> <span class="p">(</span><span class="k">const</span> <span class="n">octave_value</span><span class="o">&amp;</span> <span class="n">a</span><span class="p">,</span> <span class="k">const</span> <span class="n">octave_value</span><span class="o">&amp;</span> <span class="n">b</span><span class="p">)</span>
</div><div id="l904" class="code_block"><span class="p">{</span>
</div><div id="l905" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l906" class="code_block">
</div><div id="l907" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">fixed_type_loaded</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l908" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">is_complex_type</span><span class="p">()</span> <span class="o">&amp;&amp;</span> <span class="p">((</span><span class="n">a</span><span class="p">.</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l909" class="code_block">	 <span class="n">octave_fixed_complex</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l910" class="code_block">	<span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())))</span> <span class="p">{</span>
</div><div id="l911" class="code_block">      <span class="n">FixedComplexMatrix</span> <span class="n">m</span><span class="p">;</span>
</div><div id="l912" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l913" class="code_block">	<span class="n">m</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">a</span><span class="p">.</span><span class="n">get_rep</span><span class="p">())</span>
</div><div id="l914" class="code_block">	  <span class="p">.</span><span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l915" class="code_block">      <span class="k">else</span>
</div><div id="l916" class="code_block">	<span class="n">m</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">a</span><span class="p">.</span><span class="n">get_rep</span><span class="p">())</span>
</div><div id="l917" class="code_block">	  <span class="p">.</span><span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l918" class="code_block">
</div><div id="l919" class="code_block">      <span class="kt">int</span> <span class="n">k</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">nint_value</span><span class="p">(</span><span class="kc">true</span><span class="p">);</span>
</div><div id="l920" class="code_block">
</div><div id="l921" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="o">!</span> <span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l922" class="code_block">	<span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l923" class="code_block">	<span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l924" class="code_block">	
</div><div id="l925" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l926" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">m</span><span class="p">);</span>
</div><div id="l927" class="code_block">	<span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l928" class="code_block">	  <span class="kt">int</span> <span class="n">roff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l929" class="code_block">	  <span class="kt">int</span> <span class="n">coff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l930" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l931" class="code_block">	    <span class="n">roff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l932" class="code_block">	    <span class="n">coff</span> <span class="o">=</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l933" class="code_block">	  <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l934" class="code_block">	    <span class="n">k</span> <span class="o">=</span> <span class="o">-</span><span class="n">k</span><span class="p">;</span>
</div><div id="l935" class="code_block">	    <span class="n">roff</span> <span class="o">=</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l936" class="code_block">	    <span class="n">coff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l937" class="code_block">	  <span class="p">}</span>
</div><div id="l938" class="code_block">
</div><div id="l939" class="code_block">	  <span class="c1">// Try to be a bit intelligent about the representation of the zeros</span>
</div><div id="l940" class="code_block">	  <span class="kt">bool</span> <span class="n">same</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l941" class="code_block">	  <span class="n">Complex</span> <span class="n">is</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">).</span><span class="n">getintsize</span><span class="p">();</span>
</div><div id="l942" class="code_block">	  <span class="n">Complex</span> <span class="n">ds</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">();</span>
</div><div id="l943" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l944" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l945" class="code_block">	      <span class="k">if</span> <span class="p">((</span><span class="n">is</span> <span class="o">!=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getintsize</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">ds</span> <span class="o">!=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l946" class="code_block">		<span class="n">same</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l947" class="code_block">		<span class="k">break</span><span class="p">;</span>
</div><div id="l948" class="code_block">	      <span class="p">}</span>
</div><div id="l949" class="code_block">	    <span class="p">}</span>
</div><div id="l950" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">same</span><span class="p">)</span> <span class="k">break</span><span class="p">;</span>
</div><div id="l951" class="code_block">	  <span class="p">}</span>
</div><div id="l952" class="code_block">
</div><div id="l953" class="code_block">
</div><div id="l954" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l955" class="code_block">	    <span class="kt">int</span> <span class="n">n</span> <span class="o">=</span> <span class="n">nc</span> <span class="o">+</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l956" class="code_block">	    <span class="n">FixedComplexMatrix</span> <span class="n">r</span><span class="p">;</span>
</div><div id="l957" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="n">same</span><span class="p">)</span>
</div><div id="l958" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">),</span> <span class="n">FixedPointComplex</span><span class="p">(</span><span class="n">is</span><span class="p">,</span><span class="n">ds</span><span class="p">));</span>
</div><div id="l959" class="code_block">	    <span class="k">else</span>
</div><div id="l960" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">));</span>
</div><div id="l961" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l962" class="code_block">	      <span class="n">r</span> <span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">roff</span><span class="p">,</span> <span class="n">i</span><span class="o">+</span><span class="n">coff</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span> <span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="n">i</span><span class="p">);</span>
</div><div id="l963" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">r</span><span class="p">);</span>
</div><div id="l964" class="code_block">	  <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l965" class="code_block">	    <span class="kt">int</span> <span class="n">n</span> <span class="o">=</span> <span class="n">nr</span> <span class="o">+</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l966" class="code_block">	    <span class="n">FixedComplexMatrix</span> <span class="n">r</span><span class="p">;</span>
</div><div id="l967" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="n">same</span><span class="p">)</span>
</div><div id="l968" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">),</span> <span class="n">FixedPointComplex</span><span class="p">(</span><span class="n">is</span><span class="p">,</span><span class="n">ds</span><span class="p">));</span>
</div><div id="l969" class="code_block">	    <span class="k">else</span>
</div><div id="l970" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">));</span>
</div><div id="l971" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l972" class="code_block">	      <span class="n">r</span> <span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">roff</span><span class="p">,</span> <span class="n">i</span><span class="o">+</span><span class="n">coff</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l973" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">r</span><span class="p">);</span>
</div><div id="l974" class="code_block">	  <span class="p">}</span>
</div><div id="l975" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l976" class="code_block">	  <span class="n">FixedComplexColumnVector</span> <span class="n">r</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">diag</span> <span class="p">(</span><span class="n">k</span><span class="p">);</span>
</div><div id="l977" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">r</span><span class="p">.</span><span class="n">capacity</span> <span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l978" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">r</span><span class="p">);</span>
</div><div id="l979" class="code_block">	<span class="p">}</span>
</div><div id="l980" class="code_block">      <span class="p">}</span>
</div><div id="l981" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">((</span><span class="n">a</span><span class="p">.</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l982" class="code_block">	       <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l983" class="code_block">      <span class="n">FixedMatrix</span> <span class="n">m</span><span class="p">;</span>
</div><div id="l984" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">a</span><span class="p">.</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l985" class="code_block">	<span class="n">m</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">a</span><span class="p">.</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l986" class="code_block">      <span class="k">else</span>
</div><div id="l987" class="code_block">	<span class="n">m</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">a</span><span class="p">.</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l988" class="code_block">
</div><div id="l989" class="code_block">      <span class="kt">int</span> <span class="n">k</span> <span class="o">=</span> <span class="n">b</span><span class="p">.</span><span class="n">nint_value</span><span class="p">(</span><span class="kc">true</span><span class="p">);</span>
</div><div id="l990" class="code_block">
</div><div id="l991" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="o">!</span> <span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l992" class="code_block">	<span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">();</span>
</div><div id="l993" class="code_block">	<span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">();</span>
</div><div id="l994" class="code_block">	
</div><div id="l995" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l996" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">m</span><span class="p">);</span>
</div><div id="l997" class="code_block">	<span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l998" class="code_block">	  <span class="kt">int</span> <span class="n">roff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l999" class="code_block">	  <span class="kt">int</span> <span class="n">coff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l1000" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1001" class="code_block">	    <span class="n">roff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l1002" class="code_block">	    <span class="n">coff</span> <span class="o">=</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l1003" class="code_block">	  <span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">k</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1004" class="code_block">	    <span class="n">k</span> <span class="o">=</span> <span class="o">-</span><span class="n">k</span><span class="p">;</span>
</div><div id="l1005" class="code_block">	    <span class="n">roff</span> <span class="o">=</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l1006" class="code_block">	    <span class="n">coff</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l1007" class="code_block">	  <span class="p">}</span>
</div><div id="l1008" class="code_block">
</div><div id="l1009" class="code_block">	  <span class="c1">// Try to be a bit intelligent about the representation of the zeros</span>
</div><div id="l1010" class="code_block">	  <span class="kt">bool</span> <span class="n">same</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l1011" class="code_block">	  <span class="kt">int</span> <span class="n">is</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">).</span><span class="n">getintsize</span><span class="p">();</span>
</div><div id="l1012" class="code_block">	  <span class="kt">int</span> <span class="n">ds</span> <span class="o">=</span> <span class="n">m</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">();</span>
</div><div id="l1013" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1014" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1015" class="code_block">	      <span class="k">if</span> <span class="p">((</span><span class="n">is</span> <span class="o">!=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getintsize</span><span class="p">())</span> <span class="o">||</span> <span class="p">(</span><span class="n">ds</span> <span class="o">!=</span> <span class="n">m</span><span class="p">(</span><span class="n">i</span><span class="p">,</span><span class="n">j</span><span class="p">).</span><span class="n">getdecsize</span><span class="p">()))</span> <span class="p">{</span>
</div><div id="l1016" class="code_block">		<span class="n">same</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l1017" class="code_block">		<span class="k">break</span><span class="p">;</span>
</div><div id="l1018" class="code_block">	      <span class="p">}</span>
</div><div id="l1019" class="code_block">	    <span class="p">}</span>
</div><div id="l1020" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">same</span><span class="p">)</span> <span class="k">break</span><span class="p">;</span>
</div><div id="l1021" class="code_block">	  <span class="p">}</span>
</div><div id="l1022" class="code_block">
</div><div id="l1023" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l1024" class="code_block">	    <span class="kt">int</span> <span class="n">n</span> <span class="o">=</span> <span class="n">nc</span> <span class="o">+</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l1025" class="code_block">	    <span class="n">FixedMatrix</span> <span class="n">r</span><span class="p">;</span>
</div><div id="l1026" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="n">same</span><span class="p">)</span>
</div><div id="l1027" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">,</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">is</span><span class="p">,</span><span class="n">ds</span><span class="p">));</span>
</div><div id="l1028" class="code_block">	    <span class="k">else</span>
</div><div id="l1029" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">);</span>
</div><div id="l1030" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nc</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1031" class="code_block">	      <span class="n">r</span> <span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">roff</span><span class="p">,</span> <span class="n">i</span><span class="o">+</span><span class="n">coff</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span> <span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="n">i</span><span class="p">);</span>
</div><div id="l1032" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">r</span><span class="p">);</span>
</div><div id="l1033" class="code_block">	  <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l1034" class="code_block">	    <span class="kt">int</span> <span class="n">n</span> <span class="o">=</span> <span class="n">nr</span> <span class="o">+</span> <span class="n">k</span><span class="p">;</span>
</div><div id="l1035" class="code_block">	    <span class="n">FixedMatrix</span> <span class="n">r</span><span class="p">;</span>
</div><div id="l1036" class="code_block">	    <span class="k">if</span> <span class="p">(</span><span class="n">same</span><span class="p">)</span>
</div><div id="l1037" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">,</span><span class="n">FixedPoint</span><span class="p">(</span><span class="n">is</span><span class="p">,</span><span class="n">ds</span><span class="p">));</span>
</div><div id="l1038" class="code_block">	    <span class="k">else</span>
</div><div id="l1039" class="code_block">	      <span class="n">r</span><span class="p">.</span><span class="n">resize</span><span class="p">(</span><span class="n">n</span><span class="p">,</span><span class="n">n</span><span class="p">);</span>
</div><div id="l1040" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">nr</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l1041" class="code_block">	      <span class="n">r</span> <span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">roff</span><span class="p">,</span> <span class="n">i</span><span class="o">+</span><span class="n">coff</span><span class="p">)</span> <span class="o">=</span> <span class="n">m</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l1042" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">r</span><span class="p">);</span>
</div><div id="l1043" class="code_block">	  <span class="p">}</span>
</div><div id="l1044" class="code_block">	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l1045" class="code_block">	  <span class="n">FixedColumnVector</span> <span class="n">r</span> <span class="o">=</span> <span class="n">m</span><span class="p">.</span><span class="n">diag</span> <span class="p">(</span><span class="n">k</span><span class="p">);</span>
</div><div id="l1046" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">r</span><span class="p">.</span><span class="n">capacity</span> <span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l1047" class="code_block">	    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span> <span class="p">(</span><span class="n">r</span><span class="p">);</span>
</div><div id="l1048" class="code_block">	<span class="p">}</span>
</div><div id="l1049" class="code_block">      <span class="p">}</span>
</div><div id="l1050" class="code_block">    <span class="p">}</span> <span class="k">else</span>
</div><div id="l1051" class="code_block">      <span class="n">gripe_wrong_type_arg</span> <span class="p">(</span><span class="s">&quot;fdiag&quot;</span><span class="p">,</span> <span class="n">a</span><span class="p">);</span>
</div><div id="l1052" class="code_block">  <span class="p">}</span> <span class="k">else</span>
</div><div id="l1053" class="code_block">      <span class="n">gripe_wrong_type_arg</span> <span class="p">(</span><span class="s">&quot;fdiag&quot;</span><span class="p">,</span> <span class="n">a</span><span class="p">);</span>
</div><div id="l1054" class="code_block">  <span class="n">retval</span><span class="p">.</span><span class="n">maybe_mutate</span><span class="p">();</span>
</div><div id="l1055" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1056" class="code_block"><span class="p">}</span>
</div><div id="l1057" class="code_block">
</div><div id="l1058" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fdiag&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l1059" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;diag&quot;, &quot;fdiag&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l1060" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;diag&quot;, &quot;fdiag&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l1061" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;diag&quot;, &quot;fdiag&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l1062" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;diag&quot;, &quot;fdiag&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l1063" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">fdiag</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l1064" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1065" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {} fdiag (@var{v}, @var{k})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1066" class="code_block"><span class="s">&quot;Return a diagonal matrix with fixed point vector @var{v} on diagonal</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1067" class="code_block"><span class="s">&quot;@var{k}. The second argument is optional. If it is positive, the vector is</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1068" class="code_block"><span class="s">&quot;placed on the @var{k}-th super-diagonal. If it is negative, it is placed</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1069" class="code_block"><span class="s">&quot;on the @var{-k}-th sub-diagonal.  The default value of @var{k} is 0, and</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1070" class="code_block"><span class="s">&quot;the vector is placed on the main diagonal.  For example,</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1071" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1072" class="code_block"><span class="s">&quot;@example</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1073" class="code_block"><span class="s">&quot;fdiag (fixed(3,2,[1, 2, 3]), 1)</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1074" class="code_block"><span class="s">&quot;ans =</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1075" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1076" class="code_block"><span class="s">&quot;  0.00  1.00  0.00  0.00</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1077" class="code_block"><span class="s">&quot;  0.00  0.00  2.00  0.00</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1078" class="code_block"><span class="s">&quot;  0.00  0.00  0.00  3.00</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1079" class="code_block"><span class="s">&quot;  0.00  0.00  0.00  0.00</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1080" class="code_block"><span class="s">&quot;@end example</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1081" class="code_block"><span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1082" class="code_block"><span class="s">&quot;Note that if all of the elements of the original vector have the same fixed</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1083" class="code_block"><span class="s">&quot;point representation, then the zero elements in the matrix are created with</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1084" class="code_block"><span class="s">&quot;the same representation. Otherwise the zero elements are created with the</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1085" class="code_block"><span class="s">&quot;equivalent of the fixed point value @code{fixed(0,0,0)}.n&quot;</span>
</div><div id="l1086" class="code_block"><span class="s">&quot;@end deftypefn</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1087" class="code_block"><span class="s">&quot;@seealso{diag}&quot;</span><span class="p">)</span>
</div><div id="l1088" class="code_block"><span class="p">{</span>
</div><div id="l1089" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1090" class="code_block">
</div><div id="l1091" class="code_block">  <span class="kt">int</span> <span class="n">nargin</span> <span class="o">=</span> <span class="n">args</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l1092" class="code_block">
</div><div id="l1093" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">&amp;&amp;</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_defined</span> <span class="p">())</span>
</div><div id="l1094" class="code_block">    <span class="n">retval</span> <span class="o">=</span> <span class="n">make_fdiag</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">octave_value</span><span class="p">(</span><span class="mf">0.</span><span class="p">));</span>
</div><div id="l1095" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">2</span> <span class="o">&amp;&amp;</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_defined</span> <span class="p">()</span> <span class="o">&amp;&amp;</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">is_defined</span> <span class="p">())</span>
</div><div id="l1096" class="code_block">    <span class="n">retval</span> <span class="o">=</span> <span class="n">make_fdiag</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">));</span>
</div><div id="l1097" class="code_block">  <span class="k">else</span>
</div><div id="l1098" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l1099" class="code_block">
</div><div id="l1100" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1101" class="code_block"><span class="p">}</span>
</div><div id="l1102" class="code_block">
</div><div id="l1103" class="code_block"><span class="c1">// PKG_ADD: autoload (&quot;fatan2&quot;, &quot;fixed.oct&quot;);</span>
</div><div id="l1104" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;atan2&quot;, &quot;fatan2&quot;, &quot;fixed scalar&quot;);</span>
</div><div id="l1105" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;atan2&quot;, &quot;fatan2&quot;, &quot;fixed matrix&quot;);</span>
</div><div id="l1106" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;atan2&quot;, &quot;fatan2&quot;, &quot;fixed complex&quot;);</span>
</div><div id="l1107" class="code_block"><span class="c1">// PKG_ADD: dispatch (&quot;atan2&quot;, &quot;fatan2&quot;, &quot;fixed complex matrix&quot;);</span>
</div><div id="l1108" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">fatan2</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l1109" class="code_block">  <span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1110" class="code_block"><span class="s">&quot;@deftypefn {Loadable Function} {} fatan2 (@var{y}, @var{x})</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1111" class="code_block"><span class="s">&quot;Compute atan (Y / X) for corresponding fixed point elements of Y and X.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1112" class="code_block"><span class="s">&quot;The result is in range -pi to pi.</span><span class="se">\n</span><span class="s">&quot;</span>
</div><div id="l1113" class="code_block"><span class="s">&quot;@end deftypefn</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">)</span>
</div><div id="l1114" class="code_block"><span class="p">{</span>
</div><div id="l1115" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1116" class="code_block">  <span class="kt">int</span> <span class="n">nargin</span> <span class="o">=</span> <span class="n">args</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l1117" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nargin</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span>  
</div><div id="l1118" class="code_block">    <span class="n">FixedMatrix</span> <span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">;</span>
</div><div id="l1119" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1120" class="code_block">      <span class="n">a</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1121" class="code_block">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1122" class="code_block">      <span class="n">a</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1123" class="code_block">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1124" class="code_block">      <span class="n">a</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">())</span>
</div><div id="l1125" class="code_block">	<span class="p">.</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1126" class="code_block">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l1127" class="code_block">	     <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1128" class="code_block">      <span class="n">a</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">())</span>
</div><div id="l1129" class="code_block">	<span class="p">.</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1130" class="code_block">    <span class="k">else</span> <span class="p">{</span>
</div><div id="l1131" class="code_block">      <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l1132" class="code_block">      <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1133" class="code_block">    <span class="p">}</span>
</div><div id="l1134" class="code_block">    <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1135" class="code_block">      <span class="n">b</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1136" class="code_block">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1137" class="code_block">      <span class="n">b</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1138" class="code_block">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1139" class="code_block">      <span class="n">b</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">get_rep</span><span class="p">())</span>
</div><div id="l1140" class="code_block">	<span class="p">.</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1141" class="code_block">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l1142" class="code_block">	     <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l1143" class="code_block">      <span class="n">b</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span><span class="n">args</span><span class="p">(</span><span class="mi">1</span><span class="p">).</span><span class="n">get_rep</span><span class="p">())</span>
</div><div id="l1144" class="code_block">	<span class="p">.</span><span class="n">fixed_matrix_value</span><span class="p">();</span>
</div><div id="l1145" class="code_block">    <span class="k">else</span> <span class="p">{</span>
</div><div id="l1146" class="code_block">      <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l1147" class="code_block">      <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1148" class="code_block">    <span class="p">}</span>
</div><div id="l1149" class="code_block">    <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_matrix</span><span class="p">(</span><span class="n">atan2</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">));</span>
</div><div id="l1150" class="code_block">    <span class="n">retval</span><span class="p">.</span><span class="n">maybe_mutate</span><span class="p">();</span>
</div><div id="l1151" class="code_block">  <span class="p">}</span> <span class="k">else</span>
</div><div id="l1152" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l1153" class="code_block">
</div><div id="l1154" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l1155" class="code_block"><span class="p">}</span>
</div><div id="l1156" class="code_block">
</div><div id="l1157" class="code_block"><span class="cm">/*</span>
</div><div id="l1158" class="code_block"><span class="cm">;;; Local Variables: ***</span>
</div><div id="l1159" class="code_block"><span class="cm">;;; mode: C++ ***</span>
</div><div id="l1160" class="code_block"><span class="cm">;;; End: ***</span>
</div><div id="l1161" class="code_block"><span class="cm">*/</span>
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