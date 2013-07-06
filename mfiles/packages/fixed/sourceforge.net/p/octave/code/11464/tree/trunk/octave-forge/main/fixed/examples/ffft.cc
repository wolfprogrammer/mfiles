<!DOCTYPE html>
<!-- Server: sfn-web-5 -->


  










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
  /trunk/octave-forge/main/fixed/examples/ffft.cc
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

      <style>.XXHJrKeqvduxyqOlwUqCTkHo { display:none }</style>

    
    
    
    


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
    
  
    <a href="./">examples</a> /
    
  
 ffft.cc

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
        <span class="ico-l"><b data-icon="n" class="ico ico-table"></b> ffft.cc</span>
        &nbsp;&nbsp;
        714 lines (548 with data), 20.0 kB
      </h3>
      
        <table class="codehilitetable"><tr><td class="linenos"><div class="linenodiv"><pre>  1
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
713</pre></div></td><td class="code"><div class="codehilite"><pre><div id="l1" class="code_block"><span class="cm">/*</span>
</div><div id="l2" class="code_block">
</div><div id="l3" class="code_block"><span class="cm">Copyright (C) 2003 Motorola Inc</span>
</div><div id="l4" class="code_block"><span class="cm">Copyright (C) 2003 Laurent Mazet</span>
</div><div id="l5" class="code_block"><span class="cm">Copyright (C) 2003 David Bateman</span>
</div><div id="l6" class="code_block">
</div><div id="l7" class="code_block"><span class="cm">This program is free software; you can redistribute it and/or modify it</span>
</div><div id="l8" class="code_block"><span class="cm">under the terms of the GNU General Public License as published by the</span>
</div><div id="l9" class="code_block"><span class="cm">Free Software Foundation; either version 2, or (at your option) any</span>
</div><div id="l10" class="code_block"><span class="cm">later version.</span>
</div><div id="l11" class="code_block">
</div><div id="l12" class="code_block"><span class="cm">This program is distributed in the hope that it will be useful, but WITHOUT</span>
</div><div id="l13" class="code_block"><span class="cm">ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or</span>
</div><div id="l14" class="code_block"><span class="cm">FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License</span>
</div><div id="l15" class="code_block"><span class="cm">for more details.</span>
</div><div id="l16" class="code_block">
</div><div id="l17" class="code_block"><span class="cm">You should have received a copy of the GNU General Public License</span>
</div><div id="l18" class="code_block"><span class="cm">along with this program; see the file COPYING.  If not, see</span>
</div><div id="l19" class="code_block"><span class="cm">&lt;http://www.gnu.org/licenses/&gt;.</span>
</div><div id="l20" class="code_block">
</div><div id="l21" class="code_block"><span class="cm">In addition to the terms of the GPL, you are permitted to link</span>
</div><div id="l22" class="code_block"><span class="cm">this program with any Open Source program, as defined by the</span>
</div><div id="l23" class="code_block"><span class="cm">Open Source Initiative (www.opensource.org)</span>
</div><div id="l24" class="code_block">
</div><div id="l25" class="code_block"><span class="cm">*/</span>
</div><div id="l26" class="code_block">
</div><div id="l27" class="code_block"><span class="cp">#include &lt;cmath&gt;</span>
</div><div id="l28" class="code_block"><span class="cp">#include &lt;octave/config.h&gt;</span>
</div><div id="l29" class="code_block"><span class="cp">#include &lt;octave/oct.h&gt;</span>
</div><div id="l30" class="code_block"><span class="cp">#include &quot;ffft.h&quot;</span>
</div><div id="l31" class="code_block">
</div><div id="l32" class="code_block"><span class="cm">/*</span>
</div><div id="l33" class="code_block"><span class="cm"> *---------------------------------------------------------------------------*</span>
</div><div id="l34" class="code_block"><span class="cm"> | Module: FFT Radix4                                                        |</span>
</div><div id="l35" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l36" class="code_block"><span class="cm"> | Description: contains five radix4 - butterfly functions, and a function   |</span>
</div><div id="l37" class="code_block"><span class="cm"> |              performing the radix4 FFT.                                   |</span>
</div><div id="l38" class="code_block"><span class="cm"> |              All the butterflies have the following structure:            |</span>
</div><div id="l39" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l40" class="code_block"><span class="cm"> |                    u ____          ____ u &lt;-- [(u+y)+(x+z)]W0             |</span>
</div><div id="l41" class="code_block"><span class="cm"> |                           \      /                                        |</span>
</div><div id="l42" class="code_block"><span class="cm"> |                            \    /                                         |</span>
</div><div id="l43" class="code_block"><span class="cm"> |                    x _______\  /_______ x &lt;-- [(u-y)-j(x-z)]Wk            |</span>
</div><div id="l44" class="code_block"><span class="cm"> |                              \/                                           |</span>
</div><div id="l45" class="code_block"><span class="cm"> |                              /\                                           |</span>
</div><div id="l46" class="code_block"><span class="cm"> |                    y ______ /  \ ______ y &lt;-- [(u+y)-(x+z)]W2k            |</span>
</div><div id="l47" class="code_block"><span class="cm"> |                            /    \                                         |</span>
</div><div id="l48" class="code_block"><span class="cm"> |                           /      \                                        | </span>
</div><div id="l49" class="code_block"><span class="cm"> |                    z ___ /        \ ___ z &lt;-- [(u-y)+j(x-z)]W3k           |</span>
</div><div id="l50" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l51" class="code_block"><span class="cm"> *---------------------------------------------------------------------------*</span>
</div><div id="l52" class="code_block"><span class="cm"> */</span>
</div><div id="l53" class="code_block">
</div><div id="l54" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l55" class="code_block"><span class="kr">inline</span> <span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">corebutterfly</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l56" class="code_block">
</div><div id="l57" class="code_block">  <span class="n">apc</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">u</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">y</span><span class="p">);</span>
</div><div id="l58" class="code_block">  <span class="n">amc</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">u</span><span class="p">)</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">y</span><span class="p">);</span>
</div><div id="l59" class="code_block">  <span class="n">bpd</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">x</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">z</span><span class="p">);</span>
</div><div id="l60" class="code_block">  <span class="n">bmd</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">x</span><span class="p">)</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">z</span><span class="p">);</span>
</div><div id="l61" class="code_block"><span class="p">}</span>
</div><div id="l62" class="code_block">
</div><div id="l63" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l64" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">r4butterfly0</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l65" class="code_block">
</div><div id="l66" class="code_block">  <span class="c1">// W0, W0, W0, W0</span>
</div><div id="l67" class="code_block">
</div><div id="l68" class="code_block">  <span class="n">corebutterfly</span><span class="p">(</span><span class="n">u</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">,</span> <span class="n">z</span><span class="p">);</span>
</div><div id="l69" class="code_block">
</div><div id="l70" class="code_block">  <span class="c1">// first branch</span>
</div><div id="l71" class="code_block">  <span class="n">u</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">);</span>
</div><div id="l72" class="code_block">  <span class="c1">// third branch</span>
</div><div id="l73" class="code_block">  <span class="n">y</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">);</span>
</div><div id="l74" class="code_block">  <span class="c1">// second branch</span>
</div><div id="l75" class="code_block">  <span class="n">x</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l76" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)));</span>
</div><div id="l77" class="code_block">  <span class="c1">// last branch</span>
</div><div id="l78" class="code_block">  <span class="n">z</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l79" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)));</span>
</div><div id="l80" class="code_block">
</div><div id="l81" class="code_block"><span class="p">}</span>
</div><div id="l82" class="code_block">
</div><div id="l83" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l84" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">r4butterfly1</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l85" class="code_block">
</div><div id="l86" class="code_block">  <span class="c1">// W0, W1/16, W1/8, W3/16</span>
</div><div id="l87" class="code_block">
</div><div id="l88" class="code_block">  <span class="n">corebutterfly</span><span class="p">(</span><span class="n">u</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">,</span> <span class="n">z</span><span class="p">);</span>
</div><div id="l89" class="code_block">
</div><div id="l90" class="code_block">  <span class="c1">// first branch</span>
</div><div id="l91" class="code_block">  <span class="n">u</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">);</span>
</div><div id="l92" class="code_block">  <span class="c1">// third branch</span>
</div><div id="l93" class="code_block">  <span class="n">C</span> <span class="n">t</span><span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">));</span>
</div><div id="l94" class="code_block">  <span class="n">y</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span> <span class="o">+</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span><span class="p">,</span>
</div><div id="l95" class="code_block">		 <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span> <span class="o">-</span> <span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span><span class="p">);</span> <span class="c1">// Respect ASIC</span>
</div><div id="l96" class="code_block">  <span class="c1">// second branch</span>
</div><div id="l97" class="code_block">  <span class="n">x</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l98" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="n">n</span><span class="p">);</span>
</div><div id="l99" class="code_block">  <span class="c1">// last branch</span>
</div><div id="l100" class="code_block">  <span class="n">z</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l101" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="mi">3</span><span class="o">*</span><span class="n">n</span><span class="p">);</span>
</div><div id="l102" class="code_block">
</div><div id="l103" class="code_block"><span class="p">}</span>
</div><div id="l104" class="code_block">
</div><div id="l105" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l106" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">r4butterfly2</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l107" class="code_block">
</div><div id="l108" class="code_block">  <span class="c1">//* W0, W1/8, W1/4, W3/8</span>
</div><div id="l109" class="code_block">
</div><div id="l110" class="code_block">  <span class="n">corebutterfly</span><span class="p">(</span><span class="n">u</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">,</span> <span class="n">z</span><span class="p">);</span>
</div><div id="l111" class="code_block">
</div><div id="l112" class="code_block">  <span class="c1">// first branch</span>
</div><div id="l113" class="code_block">  <span class="n">u</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">);</span>
</div><div id="l114" class="code_block">  <span class="c1">// third branch</span>
</div><div id="l115" class="code_block">  <span class="n">y</span> <span class="o">=</span>  <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">apc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bpd</span><span class="p">)),</span>
</div><div id="l116" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bpd</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">apc</span><span class="p">)));</span>
</div><div id="l117" class="code_block">  <span class="c1">// second branch</span>
</div><div id="l118" class="code_block">  <span class="n">C</span> <span class="n">t</span><span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l119" class="code_block">	       <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)));</span>
</div><div id="l120" class="code_block">  <span class="n">x</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span> <span class="o">+</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span><span class="p">,</span>
</div><div id="l121" class="code_block">		 <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span> <span class="o">-</span> <span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="n">inv_sqrt_2</span><span class="p">);</span> <span class="c1">// Respect ASIC</span>
</div><div id="l122" class="code_block">  <span class="c1">// last branch</span>
</div><div id="l123" class="code_block">  <span class="n">t</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l124" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)));</span>
</div><div id="l125" class="code_block">  <span class="n">z</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">)</span> <span class="o">-</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">),</span>
</div><div id="l126" class="code_block">		 <span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">)</span> <span class="o">+</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">));</span> <span class="c1">// Respect ASIC</span>
</div><div id="l127" class="code_block">
</div><div id="l128" class="code_block"><span class="p">}</span>
</div><div id="l129" class="code_block">
</div><div id="l130" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l131" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">r4butterfly3</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l132" class="code_block">
</div><div id="l133" class="code_block">  <span class="c1">// W0, W3/16, W3/8, W9/16</span>
</div><div id="l134" class="code_block">
</div><div id="l135" class="code_block">  <span class="n">corebutterfly</span><span class="p">(</span><span class="n">u</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">,</span> <span class="n">z</span><span class="p">);</span>
</div><div id="l136" class="code_block">
</div><div id="l137" class="code_block">  <span class="c1">// first branch</span>
</div><div id="l138" class="code_block">  <span class="n">u</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">);</span>
</div><div id="l139" class="code_block">  <span class="c1">// third branch</span>
</div><div id="l140" class="code_block">  <span class="n">C</span> <span class="n">t</span><span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">));</span>
</div><div id="l141" class="code_block">  <span class="n">y</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">)</span> <span class="o">-</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">),</span>
</div><div id="l142" class="code_block">	 <span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">)</span> <span class="o">+</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">*</span><span class="p">(</span><span class="o">-</span><span class="n">inv_sqrt_2</span><span class="p">));</span> <span class="c1">// Respect ASIC</span>
</div><div id="l143" class="code_block">  <span class="c1">// second branch</span>
</div><div id="l144" class="code_block">  <span class="n">x</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l145" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="mi">3</span><span class="o">*</span><span class="n">n</span><span class="p">);</span>
</div><div id="l146" class="code_block">  <span class="c1">// last branch</span>
</div><div id="l147" class="code_block">  <span class="n">z</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l148" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="mi">9</span><span class="o">*</span><span class="n">n</span><span class="p">);</span>
</div><div id="l149" class="code_block">
</div><div id="l150" class="code_block"><span class="p">}</span>
</div><div id="l151" class="code_block">
</div><div id="l152" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l153" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">r4butterfly4</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l154" class="code_block">
</div><div id="l155" class="code_block">  <span class="c1">// others</span>
</div><div id="l156" class="code_block">
</div><div id="l157" class="code_block">  <span class="n">corebutterfly</span><span class="p">(</span><span class="n">u</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">,</span> <span class="n">z</span><span class="p">);</span>
</div><div id="l158" class="code_block">
</div><div id="l159" class="code_block">  <span class="c1">// first branch</span>
</div><div id="l160" class="code_block">  <span class="n">u</span> <span class="o">=</span> <span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">);</span>
</div><div id="l161" class="code_block">  <span class="c1">// third branch</span>
</div><div id="l162" class="code_block">  <span class="n">y</span> <span class="o">=</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">apc</span><span class="p">)</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">bpd</span><span class="p">))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="mi">2</span><span class="o">*</span><span class="n">n</span><span class="p">);</span>
</div><div id="l163" class="code_block">  <span class="c1">// second branch</span>
</div><div id="l164" class="code_block">  <span class="n">x</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l165" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="n">n</span><span class="p">);</span>
</div><div id="l166" class="code_block">  <span class="c1">// last branch</span>
</div><div id="l167" class="code_block">  <span class="n">z</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">-</span> <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">bmd</span><span class="p">)),</span>
</div><div id="l168" class="code_block">		 <span class="n">reshape</span><span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">amc</span><span class="p">))</span> <span class="o">+</span> <span class="n">reshape</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">bmd</span><span class="p">)))</span><span class="o">*</span><span class="n">twiddle</span><span class="p">(</span><span class="mi">3</span><span class="o">*</span><span class="n">n</span><span class="p">);</span>
</div><div id="l169" class="code_block">
</div><div id="l170" class="code_block"><span class="p">}</span>
</div><div id="l171" class="code_block">
</div><div id="l172" class="code_block"><span class="cm">/*</span>
</div><div id="l173" class="code_block"><span class="cm"> *---------------------------------------------------------------------------*</span>
</div><div id="l174" class="code_block"><span class="cm"> | Function: Radix4FFT                                                       |</span>
</div><div id="l175" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l176" class="code_block"><span class="cm"> | Description: performs a Radix4 FFT for size 256 or 1024                   |</span>
</div><div id="l177" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l178" class="code_block"><span class="cm"> | Inputs:        fft_public FFT_PARAM_PUBLIC			             |</span>
</div><div id="l179" class="code_block"><span class="cm"> | Input/Output:  realpart   CARRIERTYPE*   real part of the input data/FFT  |</span>
</div><div id="l180" class="code_block"><span class="cm"> |                imagpart   CARRIERTYPE*   imag part of the input data/FFT  |</span>
</div><div id="l181" class="code_block"><span class="cm"> *---------------------------------------------------------------------------*</span>
</div><div id="l182" class="code_block"><span class="cm"> */</span>
</div><div id="l183" class="code_block">
</div><div id="l184" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l185" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">radix4fft</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l186" class="code_block">
</div><div id="l187" class="code_block">  <span class="c1">// code for radix4FFT function</span>
</div><div id="l188" class="code_block">
</div><div id="l189" class="code_block">  <span class="kt">int</span> <span class="n">p1</span><span class="p">,</span> <span class="n">p2</span><span class="p">,</span> <span class="n">p3</span><span class="p">,</span> <span class="n">p4</span><span class="p">,</span> <span class="n">pfirst</span><span class="p">;</span>
</div><div id="l190" class="code_block">
</div><div id="l191" class="code_block">  <span class="kt">int</span> <span class="n">size_16</span> <span class="o">=</span> <span class="n">size</span><span class="o">/</span><span class="mi">16</span><span class="p">;</span>
</div><div id="l192" class="code_block">
</div><div id="l193" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">nb</span><span class="o">=</span><span class="mi">0</span><span class="p">,</span> <span class="n">nb_nb</span> <span class="o">=</span> <span class="n">x</span><span class="p">.</span><span class="n">length</span><span class="p">()</span><span class="o">/</span><span class="n">size</span><span class="p">;</span> <span class="n">nb</span><span class="o">&lt;</span><span class="n">nb_nb</span><span class="p">;</span> <span class="n">nb</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l194" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">n_but</span><span class="o">=</span><span class="mi">4</span><span class="o">*</span><span class="n">size_16</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="mi">4</span><span class="o">*</span><span class="n">size_16</span><span class="p">,</span> <span class="n">n_block</span><span class="o">=</span><span class="mi">1</span><span class="p">;</span><span class="n">n_block</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">n_but</span><span class="o">&gt;&gt;=</span><span class="mi">2</span><span class="p">,</span> <span class="n">n_block</span><span class="o">&lt;&lt;=</span><span class="mi">2</span><span class="p">)</span>
</div><div id="l195" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">block</span> <span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">block</span><span class="o">&lt;</span><span class="n">n_block</span><span class="p">;</span> <span class="n">block</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l196" class="code_block">
</div><div id="l197" class="code_block">	<span class="n">pfirst</span> <span class="o">=</span> <span class="n">p1</span> <span class="o">=</span> <span class="n">nb</span><span class="o">*</span><span class="n">size</span><span class="o">+</span><span class="n">block</span><span class="o">*</span><span class="n">n_but</span><span class="o">*</span><span class="mi">4</span><span class="p">;</span>
</div><div id="l198" class="code_block">	<span class="n">p2</span> <span class="o">=</span> <span class="n">p1</span> <span class="o">+</span> <span class="n">n_but</span><span class="p">;</span>
</div><div id="l199" class="code_block">	<span class="n">p3</span> <span class="o">=</span> <span class="n">p2</span> <span class="o">+</span> <span class="n">n_but</span><span class="p">;</span>
</div><div id="l200" class="code_block">	<span class="n">p4</span> <span class="o">=</span> <span class="n">p3</span> <span class="o">+</span> <span class="n">n_but</span><span class="p">;</span>
</div><div id="l201" class="code_block">
</div><div id="l202" class="code_block">	<span class="c1">// 1st butterfly : W0, W0, W0, W0</span>
</div><div id="l203" class="code_block">	
</div><div id="l204" class="code_block">	<span class="n">r4butterfly0</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">));</span>
</div><div id="l205" class="code_block">
</div><div id="l206" class="code_block">	<span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l207" class="code_block">	
</div><div id="l208" class="code_block">	<span class="c1">// from 1 to N/16</span>
</div><div id="l209" class="code_block">	
</div><div id="l210" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">but</span><span class="o">=</span><span class="n">n_block</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="n">size_16</span><span class="p">;</span> <span class="n">but</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">but</span><span class="o">+=</span><span class="n">n_block</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l211" class="code_block">	  
</div><div id="l212" class="code_block">	  <span class="n">r4butterfly4</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">),</span> <span class="n">but</span><span class="p">);</span>
</div><div id="l213" class="code_block">	  
</div><div id="l214" class="code_block">	  <span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l215" class="code_block">	  
</div><div id="l216" class="code_block">	<span class="p">}</span>
</div><div id="l217" class="code_block">
</div><div id="l218" class="code_block">	<span class="c1">// (N/16+1)th butterfly: W0, W1/16, W1/8, W3/16 */</span>
</div><div id="l219" class="code_block">	
</div><div id="l220" class="code_block">	<span class="n">r4butterfly1</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">),</span> <span class="n">size_16</span><span class="p">);</span>
</div><div id="l221" class="code_block">	
</div><div id="l222" class="code_block">	<span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l223" class="code_block">	
</div><div id="l224" class="code_block">	<span class="c1">// from N/16 to N/8</span>
</div><div id="l225" class="code_block">	
</div><div id="l226" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">but</span><span class="o">=</span><span class="n">size_16</span><span class="o">+</span><span class="n">n_block</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="mi">2</span><span class="o">*</span><span class="n">size_16</span><span class="p">;</span> <span class="n">but</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">but</span><span class="o">+=</span><span class="n">n_block</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l227" class="code_block">	  
</div><div id="l228" class="code_block">	  <span class="n">r4butterfly4</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">),</span> <span class="n">but</span><span class="p">);</span>
</div><div id="l229" class="code_block">	  
</div><div id="l230" class="code_block">	  <span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l231" class="code_block">	  
</div><div id="l232" class="code_block">	<span class="p">}</span>
</div><div id="l233" class="code_block">	
</div><div id="l234" class="code_block">	<span class="c1">// (N/8+1)th butterfly : W0, W1/8, W1/4, W3/8</span>
</div><div id="l235" class="code_block">	
</div><div id="l236" class="code_block">	<span class="n">r4butterfly2</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">));</span>
</div><div id="l237" class="code_block">	
</div><div id="l238" class="code_block">	<span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l239" class="code_block">
</div><div id="l240" class="code_block">	<span class="c1">// from N/8 to 3N/16</span>
</div><div id="l241" class="code_block">	
</div><div id="l242" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">but</span><span class="o">=</span><span class="mi">2</span><span class="o">*</span><span class="n">size_16</span><span class="o">+</span><span class="n">n_block</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="mi">3</span><span class="o">*</span><span class="n">size_16</span><span class="p">;</span> <span class="n">but</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">but</span><span class="o">+=</span><span class="n">n_block</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l243" class="code_block">	  
</div><div id="l244" class="code_block">	  <span class="n">r4butterfly4</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">),</span> <span class="n">but</span><span class="p">);</span>
</div><div id="l245" class="code_block">	  
</div><div id="l246" class="code_block">	  <span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l247" class="code_block">	  
</div><div id="l248" class="code_block">	<span class="p">}</span>
</div><div id="l249" class="code_block">	
</div><div id="l250" class="code_block">	<span class="c1">// (3N/16+1)th butterfly:W0, W3/16, W3/8, W9/16</span>
</div><div id="l251" class="code_block">	
</div><div id="l252" class="code_block">	<span class="n">r4butterfly3</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">),</span> <span class="n">size_16</span><span class="p">);</span>
</div><div id="l253" class="code_block">	
</div><div id="l254" class="code_block">	<span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l255" class="code_block">	
</div><div id="l256" class="code_block">	<span class="c1">// from 3N/16 to N/4</span>
</div><div id="l257" class="code_block">	
</div><div id="l258" class="code_block">	<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">but</span><span class="o">=</span><span class="mi">3</span><span class="o">*</span><span class="n">size_16</span><span class="o">+</span><span class="n">n_block</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="mi">4</span><span class="o">*</span><span class="n">size_16</span><span class="p">;</span> <span class="n">but</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">but</span><span class="o">+=</span><span class="n">n_block</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l259" class="code_block">	  
</div><div id="l260" class="code_block">	  <span class="n">r4butterfly4</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p3</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p4</span><span class="p">),</span> <span class="n">but</span><span class="p">);</span>
</div><div id="l261" class="code_block">	  
</div><div id="l262" class="code_block">	  <span class="n">p1</span><span class="o">++</span><span class="p">;</span> <span class="n">p2</span><span class="o">++</span><span class="p">;</span> <span class="n">p3</span><span class="o">++</span><span class="p">;</span> <span class="n">p4</span><span class="o">++</span><span class="p">;</span>
</div><div id="l263" class="code_block">	  
</div><div id="l264" class="code_block">	<span class="p">}</span>
</div><div id="l265" class="code_block">	
</div><div id="l266" class="code_block">      <span class="p">}</span>
</div><div id="l267" class="code_block">
</div><div id="l268" class="code_block">    <span class="c1">// last stage: butterflies (W0,W0,W0,W0) only !</span>
</div><div id="l269" class="code_block">    
</div><div id="l270" class="code_block">    <span class="kt">int</span> <span class="n">p</span><span class="o">=</span><span class="n">nb</span><span class="o">*</span><span class="n">size</span><span class="p">;</span>
</div><div id="l271" class="code_block">    <span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l272" class="code_block">    <span class="k">while</span> <span class="p">(</span><span class="n">i</span> <span class="o">&lt;</span> <span class="n">size</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l273" class="code_block">      <span class="n">r4butterfly0</span> <span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">p</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p</span><span class="o">+</span><span class="mi">1</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p</span><span class="o">+</span><span class="mi">2</span><span class="p">),</span> <span class="n">x</span><span class="p">(</span><span class="n">p</span><span class="o">+</span><span class="mi">3</span><span class="p">));</span>
</div><div id="l274" class="code_block">      <span class="n">p</span> <span class="o">+=</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l275" class="code_block">      <span class="n">i</span> <span class="o">+=</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l276" class="code_block">    <span class="p">}</span>
</div><div id="l277" class="code_block">
</div><div id="l278" class="code_block">  <span class="p">}</span>
</div><div id="l279" class="code_block">
</div><div id="l280" class="code_block">  <span class="n">normalize</span> <span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l281" class="code_block">
</div><div id="l282" class="code_block"><span class="p">}</span>
</div><div id="l283" class="code_block">
</div><div id="l284" class="code_block"><span class="cm">/*</span>
</div><div id="l285" class="code_block"><span class="cm"> *---------------------------------------------------------------------------*</span>
</div><div id="l286" class="code_block"><span class="cm"> | Function: sortingFFT                                                      |</span>
</div><div id="l287" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l288" class="code_block"><span class="cm"> | Description: this function sorts the FFT outputs using the table          |</span>
</div><div id="l289" class="code_block"><span class="cm"> |              contained in the file tables/fft_out_sort		     |</span>
</div><div id="l290" class="code_block"><span class="cm"> |                                                                           |</span>
</div><div id="l291" class="code_block"><span class="cm"> | Inputs:  param_public SORTINGFFT_PARAM_PUBLIC                             |</span>
</div><div id="l292" class="code_block"><span class="cm"> |          pr_in        CARRIERTYPE*  real part of the nonsorted FFT outputs|</span>
</div><div id="l293" class="code_block"><span class="cm"> |          pi_in        CARRIERTYPE*  imag part of the nonsorted FFT outputs|</span>
</div><div id="l294" class="code_block"><span class="cm"> | Outputs: pr_out       CARRIERTYPE*   real part of the sorted FFT outputs  |</span>
</div><div id="l295" class="code_block"><span class="cm"> |          pi_out       CARRIERTYPE*   imag part of the sorted FFT outputs  |</span>
</div><div id="l296" class="code_block"><span class="cm"> *---------------------------------------------------------------------------*</span>
</div><div id="l297" class="code_block"><span class="cm"> */</span>
</div><div id="l298" class="code_block">
</div><div id="l299" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l300" class="code_block"><span class="n">CV</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">sortingfft</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l301" class="code_block">
</div><div id="l302" class="code_block">  <span class="n">CV</span> <span class="n">y</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l303" class="code_block">
</div><div id="l304" class="code_block">  <span class="c1">// outputs sorting</span>
</div><div id="l305" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">n</span><span class="o">=</span><span class="mi">0</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="n">y</span><span class="p">.</span><span class="n">length</span><span class="p">()</span><span class="o">/</span><span class="n">size</span><span class="p">;</span> <span class="n">n</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">n</span><span class="o">++</span><span class="p">)</span>
</div><div id="l306" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">size</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l307" class="code_block">      <span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="o">+</span><span class="n">n</span><span class="o">*</span><span class="n">size</span><span class="p">)</span> <span class="o">=</span> <span class="n">x</span><span class="p">(</span><span class="n">sort</span><span class="p">(</span><span class="n">i</span><span class="p">)</span><span class="o">+</span><span class="n">n</span><span class="o">*</span><span class="n">size</span><span class="p">);</span>
</div><div id="l308" class="code_block">
</div><div id="l309" class="code_block">  <span class="k">return</span> <span class="n">y</span><span class="p">;</span>
</div><div id="l310" class="code_block"><span class="p">}</span>
</div><div id="l311" class="code_block">
</div><div id="l312" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l313" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;::</span><span class="n">generatetwiddle</span> 
</div><div id="l314" class="code_block">	<span class="p">(</span><span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l315" class="code_block">
</div><div id="l316" class="code_block">  <span class="k">const</span> <span class="kt">double</span> <span class="n">Pi2</span> <span class="o">=</span> <span class="mi">2</span> <span class="o">*</span> <span class="mf">3.14159265358979</span><span class="p">;</span> <span class="c1">// 2*pi</span>
</div><div id="l317" class="code_block">
</div><div id="l318" class="code_block">  <span class="n">twiddle</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="n">size</span><span class="p">);</span>
</div><div id="l319" class="code_block">  
</div><div id="l320" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">size</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l321" class="code_block">    <span class="n">twiddle</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">exp</span> <span class="p">(</span><span class="o">-</span><span class="n">j_complex</span><span class="o">*</span><span class="p">(</span><span class="kt">double</span><span class="p">)(</span><span class="n">i</span><span class="p">)</span><span class="o">/</span><span class="p">(</span><span class="kt">double</span><span class="p">)(</span><span class="n">size</span><span class="p">)</span><span class="o">*</span><span class="n">Pi2</span><span class="p">);</span>
</div><div id="l322" class="code_block"><span class="p">}</span>
</div><div id="l323" class="code_block">
</div><div id="l324" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l325" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;::</span><span class="n">generatetwiddle</span> 
</div><div id="l326" class="code_block">	<span class="p">(</span><span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l327" class="code_block">  <span class="k">const</span> <span class="kt">double</span> <span class="n">Pi2</span> <span class="o">=</span> <span class="mi">2</span> <span class="o">*</span> <span class="mf">3.14159265358979</span><span class="p">;</span> <span class="c1">// 2*pi</span>
</div><div id="l328" class="code_block">
</div><div id="l329" class="code_block">  <span class="n">ComplexRowVector</span> <span class="n">twiddle_double</span> <span class="p">(</span><span class="n">size</span><span class="p">);</span>
</div><div id="l330" class="code_block">  
</div><div id="l331" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">size</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l332" class="code_block">   <span class="n">twiddle_double</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">exp</span> <span class="p">(</span><span class="o">-</span><span class="n">j_complex</span><span class="o">*</span><span class="p">(</span><span class="kt">double</span><span class="p">)(</span><span class="n">i</span><span class="p">)</span><span class="o">/</span><span class="p">(</span><span class="kt">double</span><span class="p">)(</span><span class="n">size</span><span class="p">)</span><span class="o">*</span><span class="n">Pi2</span><span class="p">);</span>
</div><div id="l333" class="code_block">
</div><div id="l334" class="code_block">  <span class="n">twiddle</span> <span class="o">=</span> <span class="n">FixedComplexRowVector</span> <span class="p">(</span><span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">,</span> <span class="n">twiddle_double</span><span class="p">);</span>
</div><div id="l335" class="code_block">  
</div><div id="l336" class="code_block"><span class="p">}</span>
</div><div id="l337" class="code_block">
</div><div id="l338" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l339" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">generatesort</span> <span class="p">()</span> <span class="p">{</span>
</div><div id="l340" class="code_block">
</div><div id="l341" class="code_block">  <span class="c1">// Resize and fill sort with zeros..</span>
</div><div id="l342" class="code_block">  <span class="n">sort</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="mi">0</span><span class="p">);</span>
</div><div id="l343" class="code_block">  <span class="n">sort</span><span class="p">.</span><span class="n">resize_and_fill</span> <span class="p">(</span><span class="n">size</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l344" class="code_block">
</div><div id="l345" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">size</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l346" class="code_block">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">1</span><span class="p">,</span> <span class="n">k</span><span class="o">=</span><span class="n">size</span><span class="o">/</span><span class="mi">4</span><span class="p">;</span> <span class="n">j</span><span class="o">&lt;</span><span class="n">size</span><span class="p">;</span> <span class="n">j</span><span class="o">&lt;&lt;=</span><span class="mi">2</span><span class="p">,</span> <span class="n">k</span><span class="o">&gt;&gt;=</span><span class="mi">2</span><span class="p">)</span>
</div><div id="l347" class="code_block">      <span class="n">sort</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">+=</span> <span class="n">j</span><span class="o">*</span><span class="p">((</span><span class="n">i</span><span class="o">/</span><span class="n">k</span><span class="p">)</span><span class="o">%</span><span class="mi">4</span><span class="p">);</span>
</div><div id="l348" class="code_block"><span class="p">}</span>
</div><div id="l349" class="code_block">
</div><div id="l350" class="code_block"><span class="k">template</span><span class="o">&lt;&gt;</span>
</div><div id="l351" class="code_block"><span class="kr">inline</span> <span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;::</span><span class="n">normalize</span> 
</div><div id="l352" class="code_block">	<span class="p">(</span><span class="n">FixedComplexRowVector</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l353" class="code_block">
</div><div id="l354" class="code_block">  <span class="cm">/*</span>
</div><div id="l355" class="code_block"><span class="cm">    We reshape data before each butterfly, so we have to multiply </span>
</div><div id="l356" class="code_block"><span class="cm">    by sqrt(size).</span>
</div><div id="l357" class="code_block"><span class="cm">  */</span>
</div><div id="l358" class="code_block">
</div><div id="l359" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="n">x</span><span class="p">.</span><span class="n">length</span><span class="p">();</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l360" class="code_block">    <span class="n">x</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">FixedPointComplex</span>  <span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">i</span><span class="p">))</span><span class="o">&lt;&lt;</span><span class="n">output_gain_fp</span><span class="p">,</span>
</div><div id="l361" class="code_block">			      <span class="n">imag</span><span class="p">(</span><span class="n">x</span><span class="p">(</span><span class="n">i</span><span class="p">))</span><span class="o">&lt;&lt;</span><span class="n">output_gain_fp</span><span class="p">);</span>
</div><div id="l362" class="code_block"><span class="p">}</span>
</div><div id="l363" class="code_block">
</div><div id="l364" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l365" class="code_block"><span class="kr">inline</span> <span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;::</span><span class="n">normalize</span> 
</div><div id="l366" class="code_block">	<span class="p">(</span><span class="n">ComplexRowVector</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l367" class="code_block">
</div><div id="l368" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="n">x</span><span class="p">.</span><span class="n">length</span><span class="p">();</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l369" class="code_block">    <span class="n">x</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">x</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">/</span> <span class="n">output_gain</span><span class="p">;</span>
</div><div id="l370" class="code_block">
</div><div id="l371" class="code_block"><span class="p">}</span>
</div><div id="l372" class="code_block">
</div><div id="l373" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l374" class="code_block"><span class="kr">inline</span> <span class="n">FixedPoint</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;::</span>
</div><div id="l375" class="code_block">	<span class="n">reshape</span> <span class="p">(</span><span class="n">FixedPoint</span> <span class="n">t</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l376" class="code_block">  <span class="k">return</span> <span class="p">(</span><span class="n">t</span><span class="o">&gt;&gt;</span><span class="mi">1</span><span class="p">);</span>
</div><div id="l377" class="code_block"><span class="p">}</span>
</div><div id="l378" class="code_block">
</div><div id="l379" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l380" class="code_block"><span class="kr">inline</span> <span class="n">FixedPointComplex</span> 
</div><div id="l381" class="code_block"><span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;::</span><span class="n">reshape</span>
</div><div id="l382" class="code_block">	 <span class="p">(</span><span class="n">FixedPointComplex</span>  <span class="n">t</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l383" class="code_block">  <span class="k">return</span> <span class="p">(</span><span class="n">FixedPointComplex</span>  <span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">&gt;&gt;</span><span class="mi">1</span><span class="p">,</span> <span class="n">imag</span><span class="p">(</span><span class="n">t</span><span class="p">)</span><span class="o">&gt;&gt;</span><span class="mi">1</span><span class="p">));</span>
</div><div id="l384" class="code_block"><span class="p">}</span>
</div><div id="l385" class="code_block">
</div><div id="l386" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l387" class="code_block"><span class="kr">inline</span> <span class="n">Complex</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;::</span><span class="n">reshape</span> <span class="p">(</span><span class="n">Complex</span> <span class="n">t</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l388" class="code_block">
</div><div id="l389" class="code_block">  <span class="k">return</span> <span class="p">(</span><span class="n">t</span><span class="p">);</span>
</div><div id="l390" class="code_block"><span class="p">}</span>
</div><div id="l391" class="code_block">
</div><div id="l392" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l393" class="code_block"><span class="kr">inline</span> <span class="kt">double</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;::</span><span class="n">reshape</span> <span class="p">(</span><span class="kt">double</span> <span class="n">t</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l394" class="code_block">
</div><div id="l395" class="code_block">  <span class="k">return</span> <span class="p">(</span><span class="n">t</span><span class="p">);</span>
</div><div id="l396" class="code_block"><span class="p">}</span>
</div><div id="l397" class="code_block">
</div><div id="l398" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l399" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;::</span>
</div><div id="l400" class="code_block">	<span class="n">computetemplatevalues</span> <span class="p">(</span><span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">FftInputI</span><span class="p">,</span> 
</div><div id="l401" class="code_block">	<span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">FftInputD</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l402" class="code_block">
</div><div id="l403" class="code_block">  <span class="n">j_complex</span> <span class="o">=</span> <span class="n">Complex</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="mf">1.</span><span class="p">);</span>
</div><div id="l404" class="code_block">  <span class="n">output_gain_fp</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>
</div><div id="l405" class="code_block">  <span class="kt">long</span> <span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="n">size</span><span class="p">;</span>
</div><div id="l406" class="code_block">  <span class="k">while</span> <span class="p">(</span><span class="n">i</span> <span class="o">&gt;&gt;=</span><span class="mi">1</span><span class="p">)</span>
</div><div id="l407" class="code_block">    <span class="n">output_gain_fp</span><span class="o">++</span><span class="p">;</span>
</div><div id="l408" class="code_block">  <span class="n">output_gain_fp</span> <span class="o">=</span> <span class="n">output_gain_fp</span> <span class="o">/</span> <span class="mi">2</span><span class="p">;</span>
</div><div id="l409" class="code_block">  <span class="n">inv_sqrt_2</span> <span class="o">=</span> <span class="n">FixedPoint</span><span class="p">(</span><span class="n">FftInputI</span><span class="p">,</span> <span class="n">FftInputD</span><span class="p">,</span> <span class="mi">1</span> <span class="o">/</span> <span class="n">sqrt</span><span class="p">(</span><span class="mf">2.0</span><span class="p">));</span>
</div><div id="l410" class="code_block"><span class="p">}</span>
</div><div id="l411" class="code_block">
</div><div id="l412" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l413" class="code_block"><span class="kt">void</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;::</span><span class="n">computetemplatevalues</span> <span class="p">(</span>
</div><div id="l414" class="code_block">	<span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">FftInputI</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">FftInputD</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l415" class="code_block">
</div><div id="l416" class="code_block">  <span class="n">j_complex</span> <span class="o">=</span> <span class="n">Complex</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="mf">1.</span><span class="p">);</span>
</div><div id="l417" class="code_block">  <span class="n">output_gain</span> <span class="o">=</span> <span class="n">sqrt</span><span class="p">(</span><span class="kt">double</span><span class="p">(</span><span class="n">size</span><span class="p">));</span>
</div><div id="l418" class="code_block">  <span class="n">inv_sqrt_2</span> <span class="o">=</span> <span class="mi">1</span> <span class="o">/</span> <span class="n">sqrt</span><span class="p">(</span><span class="mf">2.0</span><span class="p">);</span>
</div><div id="l419" class="code_block"><span class="p">}</span>
</div><div id="l420" class="code_block">
</div><div id="l421" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l422" class="code_block"><span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;::</span><span class="n">Fft</span> 
</div><div id="l423" class="code_block">	<span class="p">(</span><span class="k">const</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">n</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l424" class="code_block">
</div><div id="l425" class="code_block">  <span class="n">size</span> <span class="o">=</span> <span class="n">n</span><span class="p">;</span>
</div><div id="l426" class="code_block">
</div><div id="l427" class="code_block">  <span class="kt">int</span> <span class="n">quot</span> <span class="o">=</span> <span class="n">n</span> <span class="o">/</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l428" class="code_block">  <span class="kt">int</span> <span class="n">rem</span> <span class="o">=</span> <span class="n">n</span> <span class="o">%</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l429" class="code_block">  <span class="k">while</span> <span class="p">((</span><span class="n">rem</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">quot</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l430" class="code_block">    <span class="n">rem</span> <span class="o">=</span> <span class="n">quot</span> <span class="o">%</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l431" class="code_block">    <span class="n">quot</span> <span class="o">=</span> <span class="n">quot</span> <span class="o">/</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l432" class="code_block">  <span class="p">}</span>
</div><div id="l433" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">rem</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l434" class="code_block">    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fft: invalid radix 4 fft</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span>
</div><div id="l435" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l436" class="code_block">  <span class="p">}</span>
</div><div id="l437" class="code_block">
</div><div id="l438" class="code_block">  <span class="n">computetemplatevalues</span><span class="p">(</span><span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">);</span>
</div><div id="l439" class="code_block">  <span class="n">generatetwiddle</span><span class="p">(</span><span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">);</span>
</div><div id="l440" class="code_block">  <span class="n">generatesort</span><span class="p">();</span>
</div><div id="l441" class="code_block"><span class="p">}</span>
</div><div id="l442" class="code_block">
</div><div id="l443" class="code_block"><span class="k">template</span> <span class="o">&lt;&gt;</span>
</div><div id="l444" class="code_block"><span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;::</span><span class="n">Fft</span>
</div><div id="l445" class="code_block">	<span class="p">(</span><span class="k">const</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">n</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l446" class="code_block">
</div><div id="l447" class="code_block">  <span class="n">size</span> <span class="o">=</span> <span class="n">n</span><span class="p">;</span>
</div><div id="l448" class="code_block">
</div><div id="l449" class="code_block">  <span class="kt">int</span> <span class="n">quot</span> <span class="o">=</span> <span class="n">n</span> <span class="o">/</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l450" class="code_block">  <span class="kt">int</span> <span class="n">rem</span> <span class="o">=</span> <span class="n">n</span> <span class="o">%</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l451" class="code_block">  <span class="k">while</span> <span class="p">((</span><span class="n">rem</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">quot</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">))</span> <span class="p">{</span>
</div><div id="l452" class="code_block">    <span class="n">rem</span> <span class="o">=</span> <span class="n">quot</span> <span class="o">%</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l453" class="code_block">    <span class="n">quot</span> <span class="o">=</span> <span class="n">quot</span> <span class="o">/</span> <span class="mi">4</span><span class="p">;</span>
</div><div id="l454" class="code_block">  <span class="p">}</span>
</div><div id="l455" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">rem</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l456" class="code_block">    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fft: invalid radix 4 fft</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span>
</div><div id="l457" class="code_block">    <span class="k">return</span><span class="p">;</span>
</div><div id="l458" class="code_block">  <span class="p">}</span>
</div><div id="l459" class="code_block">
</div><div id="l460" class="code_block">  <span class="n">computetemplatevalues</span><span class="p">();</span>
</div><div id="l461" class="code_block">  <span class="n">generatetwiddle</span><span class="p">();</span>
</div><div id="l462" class="code_block">  <span class="n">generatesort</span><span class="p">();</span>
</div><div id="l463" class="code_block"><span class="p">}</span>
</div><div id="l464" class="code_block">
</div><div id="l465" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l466" class="code_block"><span class="n">CV</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">process</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l467" class="code_block">
</div><div id="l468" class="code_block">  <span class="n">CV</span> <span class="n">y</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l469" class="code_block">
</div><div id="l470" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">y</span><span class="p">.</span><span class="n">length</span><span class="p">()</span><span class="o">%</span><span class="n">size</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l471" class="code_block">    <span class="n">error</span><span class="p">(</span><span class="s">&quot;fft: incorrect length of fft</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span>
</div><div id="l472" class="code_block">    <span class="k">return</span> <span class="n">y</span><span class="p">;</span>
</div><div id="l473" class="code_block">  <span class="p">}</span>
</div><div id="l474" class="code_block">  <span class="n">radix4fft</span><span class="p">(</span><span class="n">y</span><span class="p">);</span>
</div><div id="l475" class="code_block">
</div><div id="l476" class="code_block">  <span class="k">return</span> <span class="p">(</span><span class="n">sortingfft</span><span class="p">(</span><span class="n">y</span><span class="p">));</span>
</div><div id="l477" class="code_block"><span class="p">}</span>
</div><div id="l478" class="code_block">
</div><div id="l479" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">S</span><span class="p">,</span> <span class="k">class</span> <span class="nc">C</span><span class="p">,</span> <span class="k">class</span> <span class="nc">CV</span><span class="o">&gt;</span>
</div><div id="l480" class="code_block"><span class="n">CV</span> <span class="n">Ifft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">process</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l481" class="code_block">
</div><div id="l482" class="code_block">  <span class="n">CV</span> <span class="n">y</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l483" class="code_block">
</div><div id="l484" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="n">y</span><span class="p">.</span><span class="n">length</span><span class="p">();</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l485" class="code_block">    <span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">)),</span> <span class="n">real</span><span class="p">(</span><span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">)));</span>
</div><div id="l486" class="code_block">
</div><div id="l487" class="code_block">  <span class="n">y</span> <span class="o">=</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;::</span><span class="n">process</span> <span class="p">(</span><span class="n">y</span><span class="p">);</span>
</div><div id="l488" class="code_block">
</div><div id="l489" class="code_block">  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">,</span> <span class="n">l</span><span class="o">=</span><span class="n">y</span><span class="p">.</span><span class="n">length</span><span class="p">();</span> <span class="n">i</span><span class="o">&lt;</span><span class="n">l</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l490" class="code_block">    <span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">C</span> <span class="p">(</span><span class="n">imag</span><span class="p">(</span><span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">)),</span> <span class="n">real</span><span class="p">(</span><span class="n">y</span><span class="p">(</span><span class="n">i</span><span class="p">)));</span>
</div><div id="l491" class="code_block">
</div><div id="l492" class="code_block">  <span class="k">return</span> <span class="n">y</span><span class="p">;</span>
</div><div id="l493" class="code_block"><span class="p">}</span>
</div><div id="l494" class="code_block">
</div><div id="l495" class="code_block"><span class="cm">/* class instantiation */</span>
</div><div id="l496" class="code_block">
</div><div id="l497" class="code_block"><span class="k">template</span> <span class="k">class</span> <span class="nc">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;</span><span class="p">;</span>
</div><div id="l498" class="code_block"><span class="k">template</span> <span class="k">class</span> <span class="nc">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;</span><span class="p">;</span>
</div><div id="l499" class="code_block">
</div><div id="l500" class="code_block"><span class="k">template</span> <span class="k">class</span> <span class="nc">Ifft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;</span><span class="p">;</span>
</div><div id="l501" class="code_block"><span class="k">template</span> <span class="k">class</span> <span class="nc">Ifft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;</span><span class="p">;</span>
</div><div id="l502" class="code_block">
</div><div id="l503" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">ffft</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l504" class="code_block"><span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l505" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =}  ffft (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l506" class="code_block"><span class="s">Radix-4 fft in floating and fixed point for vectors of length 4^@var{n},</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l507" class="code_block"><span class="s">where @var{n} is an integer. The variable @var{x} can be a either a row of</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l508" class="code_block"><span class="s">column vector, in which case a single fft is carried out over the vector</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l509" class="code_block"><span class="s">of length 4^@var{n}. If @var{x} is a matrix, the fft is carried on each</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l510" class="code_block"><span class="s">column of @var{x} and the matrix must contain 4^@var{n} rows.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l511" class="code_block"><span class="se">\n</span><span class="s">\</span>
</div><div id="l512" class="code_block"><span class="s">The radix-4 fft is implemented in a manner that attempts to approximate</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l513" class="code_block"><span class="s">how it will be implemented in hardware, rather than use a generic butterfly.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l514" class="code_block"><span class="s">The radix-4 algorithm is faster and more precise than the equivalent radix-2</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l515" class="code_block"><span class="s">algorithm, and thus is preferred for hardware implementation.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l516" class="code_block"><span class="s">@seealso{fifft}</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l517" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">)</span>
</div><div id="l518" class="code_block"><span class="p">{</span>
</div><div id="l519" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l520" class="code_block">
</div><div id="l521" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">.</span><span class="n">length</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l522" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l523" class="code_block">  <span class="k">else</span> <span class="p">{</span>
</div><div id="l524" class="code_block">
</div><div id="l525" class="code_block">    <span class="k">if</span> <span class="p">((</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l526" class="code_block">	<span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l527" class="code_block">      <span class="n">FixedComplexMatrix</span> <span class="n">f</span><span class="p">;</span>
</div><div id="l528" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l529" class="code_block">	<span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span>
</div><div id="l530" class="code_block">	  <span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l531" class="code_block">      <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l532" class="code_block">	       <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l533" class="code_block">	<span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span> 
</div><div id="l534" class="code_block">	     <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l535" class="code_block">
</div><div id="l536" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l537" class="code_block">	<span class="kt">bool</span> <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l538" class="code_block">	<span class="kt">int</span> <span class="n">is</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">std</span><span class="o">::</span><span class="n">max</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getintsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">(),</span>
</div><div id="l539" class="code_block">			       <span class="n">imag</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getintsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">());</span>
</div><div id="l540" class="code_block">	<span class="kt">int</span> <span class="n">ds</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">std</span><span class="o">::</span><span class="n">max</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getdecsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">(),</span>
</div><div id="l541" class="code_block">			       <span class="n">imag</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getdecsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">());</span>
</div><div id="l542" class="code_block">	
</div><div id="l543" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l544" class="code_block">	  <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l545" class="code_block">	  <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l546" class="code_block">	<span class="p">}</span>
</div><div id="l547" class="code_block">	
</div><div id="l548" class="code_block">	<span class="n">Fft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;</span> 
</div><div id="l549" class="code_block">	  <span class="n">fft_radix4</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">);</span>
</div><div id="l550" class="code_block">	
</div><div id="l551" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l552" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l553" class="code_block">	    <span class="n">FixedComplexRowVector</span> <span class="n">x</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">());</span>
</div><div id="l554" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l555" class="code_block">	      <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">);</span> 
</div><div id="l556" class="code_block">	    <span class="n">x</span> <span class="o">=</span> <span class="n">fft_radix4</span><span class="p">.</span><span class="n">process</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l557" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l558" class="code_block">	      <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">);</span> 
</div><div id="l559" class="code_block">	  <span class="p">}</span>
</div><div id="l560" class="code_block">
</div><div id="l561" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">rowvect</span><span class="p">)</span>
</div><div id="l562" class="code_block">	    <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l563" class="code_block">
</div><div id="l564" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l565" class="code_block">	  <span class="n">retval</span><span class="p">.</span><span class="n">maybe_mutate</span><span class="p">();</span>
</div><div id="l566" class="code_block">	<span class="p">}</span>
</div><div id="l567" class="code_block">      <span class="p">}</span>
</div><div id="l568" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l569" class="code_block">      <span class="n">ComplexMatrix</span> <span class="n">f</span><span class="p">;</span>
</div><div id="l570" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_matrix_type</span><span class="p">())</span>
</div><div id="l571" class="code_block">	<span class="n">f</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">complex_matrix_value</span><span class="p">();</span>
</div><div id="l572" class="code_block">      <span class="k">else</span> 
</div><div id="l573" class="code_block">	<span class="n">error</span><span class="p">(</span><span class="s">&quot;ffft: must be called with a floating or fixed point vector</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span>
</div><div id="l574" class="code_block">
</div><div id="l575" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l576" class="code_block">	<span class="kt">bool</span> <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l577" class="code_block">
</div><div id="l578" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l579" class="code_block">	  <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l580" class="code_block">	  <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l581" class="code_block">	<span class="p">}</span>
</div><div id="l582" class="code_block">	
</div><div id="l583" class="code_block">	<span class="n">Fft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;</span> <span class="n">fft_radix4</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">());</span>
</div><div id="l584" class="code_block">	
</div><div id="l585" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l586" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l587" class="code_block">	    <span class="n">ComplexRowVector</span> <span class="n">x</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">());</span>
</div><div id="l588" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l589" class="code_block">	      <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">);</span> 
</div><div id="l590" class="code_block">	    <span class="n">x</span> <span class="o">=</span> <span class="n">fft_radix4</span><span class="p">.</span><span class="n">process</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l591" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l592" class="code_block">	      <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">);</span> 
</div><div id="l593" class="code_block">	  <span class="p">}</span>
</div><div id="l594" class="code_block">
</div><div id="l595" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">rowvect</span><span class="p">)</span>
</div><div id="l596" class="code_block">	    <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l597" class="code_block">
</div><div id="l598" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="n">octave_value</span><span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l599" class="code_block">	<span class="p">}</span>
</div><div id="l600" class="code_block">      <span class="p">}</span>
</div><div id="l601" class="code_block">    <span class="p">}</span>
</div><div id="l602" class="code_block">  <span class="p">}</span>
</div><div id="l603" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l604" class="code_block"><span class="p">}</span>
</div><div id="l605" class="code_block">
</div><div id="l606" class="code_block"><span class="n">DEFUN_DLD</span> <span class="p">(</span><span class="n">fifft</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="p">,</span>
</div><div id="l607" class="code_block"><span class="s">&quot;-*- texinfo -*-</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l608" class="code_block"><span class="s">@deftypefn {Loadable Function} {@var{y} =}  fifft (@var{x})</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l609" class="code_block"><span class="s">Radix-4 ifft in fixed point for vectors of length 4^@var{n}, where.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l610" class="code_block"><span class="s">@var{n} is an integer. The variable @var{x} can be a either a row of</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l611" class="code_block"><span class="s">column vector, in which case a single ifft is carried out over the vector</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l612" class="code_block"><span class="s">of length 4^@var{n}. If @var{x} is a matrix, the ifft is carried on each</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l613" class="code_block"><span class="s">column of @var{x} and the matrix must contain 4^@var{n} rows.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l614" class="code_block"><span class="se">\n</span><span class="s">\</span>
</div><div id="l615" class="code_block"><span class="s">The radix-4 ifft is implemented in a manner that attempts to approximate</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l616" class="code_block"><span class="s">how it will be implemented in hardware, rather than use a generic butterfly.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l617" class="code_block"><span class="s">The radix-4 algorithm is faster and more precise than the equivalent radix-2</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l618" class="code_block"><span class="s">algorithm, and thus is preferred for hardware implementation.</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l619" class="code_block"><span class="s">@seealso{ffft}</span><span class="se">\n</span><span class="s">\</span>
</div><div id="l620" class="code_block"><span class="s">@end deftypefn&quot;</span><span class="p">)</span>
</div><div id="l621" class="code_block"><span class="p">{</span>
</div><div id="l622" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l623" class="code_block">
</div><div id="l624" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">.</span><span class="n">length</span><span class="p">()</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span>
</div><div id="l625" class="code_block">    <span class="n">print_usage</span> <span class="p">();</span>
</div><div id="l626" class="code_block">  <span class="k">else</span> <span class="p">{</span>
</div><div id="l627" class="code_block">
</div><div id="l628" class="code_block">    <span class="k">if</span> <span class="p">((</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span> <span class="o">||</span>
</div><div id="l629" class="code_block">	<span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">()))</span> <span class="p">{</span>
</div><div id="l630" class="code_block">      <span class="n">FixedComplexMatrix</span> <span class="n">f</span><span class="p">;</span>
</div><div id="l631" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> <span class="n">octave_fixed_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l632" class="code_block">	<span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_matrix</span><span class="o">&amp;</span><span class="p">)</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span>
</div><div id="l633" class="code_block">	  <span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l634" class="code_block">      <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">type_id</span> <span class="p">()</span> <span class="o">==</span> 
</div><div id="l635" class="code_block">	       <span class="n">octave_fixed_complex_matrix</span><span class="o">::</span><span class="n">static_type_id</span> <span class="p">())</span>
</div><div id="l636" class="code_block">	<span class="n">f</span> <span class="o">=</span> <span class="p">((</span><span class="k">const</span> <span class="n">octave_fixed_complex_matrix</span><span class="o">&amp;</span><span class="p">)</span> 
</div><div id="l637" class="code_block">	     <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">get_rep</span><span class="p">()).</span><span class="n">fixed_complex_matrix_value</span><span class="p">();</span>
</div><div id="l638" class="code_block">
</div><div id="l639" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l640" class="code_block">	<span class="kt">bool</span> <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l641" class="code_block">	<span class="kt">int</span> <span class="n">is</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">std</span><span class="o">::</span><span class="n">max</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getintsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">(),</span>
</div><div id="l642" class="code_block">			       <span class="n">imag</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getintsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">());</span>
</div><div id="l643" class="code_block">	<span class="kt">int</span> <span class="n">ds</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">std</span><span class="o">::</span><span class="n">max</span><span class="p">(</span><span class="n">real</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getdecsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">(),</span>
</div><div id="l644" class="code_block">			       <span class="n">imag</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">getdecsize</span><span class="p">()).</span><span class="n">row_max</span><span class="p">().</span><span class="n">max</span><span class="p">());</span>
</div><div id="l645" class="code_block">	
</div><div id="l646" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l647" class="code_block">	  <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l648" class="code_block">	  <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l649" class="code_block">	<span class="p">}</span>
</div><div id="l650" class="code_block">	
</div><div id="l651" class="code_block">	<span class="n">Ifft</span><span class="o">&lt;</span><span class="n">FixedPoint</span><span class="p">,</span><span class="n">FixedPointComplex</span><span class="p">,</span><span class="n">FixedComplexRowVector</span><span class="o">&gt;</span> 
</div><div id="l652" class="code_block">	  <span class="n">ifft_radix4</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">(),</span> <span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">);</span>
</div><div id="l653" class="code_block">	
</div><div id="l654" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l655" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l656" class="code_block">	    <span class="n">FixedComplexRowVector</span> <span class="n">x</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">());</span>
</div><div id="l657" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l658" class="code_block">	      <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">);</span> 
</div><div id="l659" class="code_block">	    <span class="n">x</span> <span class="o">=</span> <span class="n">ifft_radix4</span><span class="p">.</span><span class="n">process</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l660" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l661" class="code_block">	      <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">);</span> 
</div><div id="l662" class="code_block">	  <span class="p">}</span>
</div><div id="l663" class="code_block">
</div><div id="l664" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">rowvect</span><span class="p">)</span>
</div><div id="l665" class="code_block">	    <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l666" class="code_block">
</div><div id="l667" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="k">new</span> <span class="n">octave_fixed_complex_matrix</span> <span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l668" class="code_block">	  <span class="n">retval</span><span class="p">.</span><span class="n">maybe_mutate</span><span class="p">();</span>
</div><div id="l669" class="code_block">	<span class="p">}</span>
</div><div id="l670" class="code_block">      <span class="p">}</span>
</div><div id="l671" class="code_block">    <span class="p">}</span> <span class="k">else</span> <span class="p">{</span>
</div><div id="l672" class="code_block">      <span class="n">ComplexMatrix</span> <span class="n">f</span><span class="p">;</span>
</div><div id="l673" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">is_matrix_type</span><span class="p">())</span>
</div><div id="l674" class="code_block">	<span class="n">f</span> <span class="o">=</span> <span class="n">args</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">complex_matrix_value</span><span class="p">();</span>
</div><div id="l675" class="code_block">      <span class="k">else</span> 
</div><div id="l676" class="code_block">	<span class="n">error</span><span class="p">(</span><span class="s">&quot;fifft: must be called with a floating or fixed point vector</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span>
</div><div id="l677" class="code_block">
</div><div id="l678" class="code_block">      <span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l679" class="code_block">	<span class="kt">bool</span> <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l680" class="code_block">
</div><div id="l681" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l682" class="code_block">	  <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l683" class="code_block">	  <span class="n">rowvect</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l684" class="code_block">	<span class="p">}</span>
</div><div id="l685" class="code_block">	
</div><div id="l686" class="code_block">	<span class="n">Ifft</span><span class="o">&lt;</span><span class="kt">double</span><span class="p">,</span><span class="n">Complex</span><span class="p">,</span><span class="n">ComplexRowVector</span><span class="o">&gt;</span> <span class="n">ifft_radix4</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">());</span>
</div><div id="l687" class="code_block">	
</div><div id="l688" class="code_block">	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">error_state</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l689" class="code_block">	  <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">cols</span><span class="p">();</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span>
</div><div id="l690" class="code_block">	    <span class="n">ComplexRowVector</span> <span class="n">x</span><span class="p">(</span><span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">());</span>
</div><div id="l691" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l692" class="code_block">	      <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">)</span> <span class="o">=</span> <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">);</span> 
</div><div id="l693" class="code_block">	    <span class="n">x</span> <span class="o">=</span> <span class="n">ifft_radix4</span><span class="p">.</span><span class="n">process</span><span class="p">(</span><span class="n">x</span><span class="p">);</span>
</div><div id="l694" class="code_block">	    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">f</span><span class="p">.</span><span class="n">rows</span><span class="p">();</span> <span class="n">j</span><span class="o">++</span><span class="p">)</span>
</div><div id="l695" class="code_block">	      <span class="n">f</span><span class="p">(</span><span class="n">j</span><span class="p">,</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">x</span><span class="p">(</span><span class="n">j</span><span class="p">);</span> 
</div><div id="l696" class="code_block">	  <span class="p">}</span>
</div><div id="l697" class="code_block">
</div><div id="l698" class="code_block">	  <span class="k">if</span> <span class="p">(</span><span class="n">rowvect</span><span class="p">)</span>
</div><div id="l699" class="code_block">	    <span class="n">f</span> <span class="o">=</span> <span class="n">f</span><span class="p">.</span><span class="n">transpose</span><span class="p">();</span>
</div><div id="l700" class="code_block">
</div><div id="l701" class="code_block">	  <span class="n">retval</span> <span class="o">=</span> <span class="n">octave_value</span><span class="p">(</span><span class="n">f</span><span class="p">);</span>
</div><div id="l702" class="code_block">	<span class="p">}</span>
</div><div id="l703" class="code_block">      <span class="p">}</span>
</div><div id="l704" class="code_block">    <span class="p">}</span>
</div><div id="l705" class="code_block">  <span class="p">}</span>
</div><div id="l706" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l707" class="code_block"><span class="p">}</span>
</div><div id="l708" class="code_block">
</div><div id="l709" class="code_block"><span class="cm">/*</span>
</div><div id="l710" class="code_block"><span class="cm">;;; Local Variables: ***</span>
</div><div id="l711" class="code_block"><span class="cm">;;; mode: C++ ***</span>
</div><div id="l712" class="code_block"><span class="cm">;;; End: ***</span>
</div><div id="l713" class="code_block"><span class="cm">*/</span>
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