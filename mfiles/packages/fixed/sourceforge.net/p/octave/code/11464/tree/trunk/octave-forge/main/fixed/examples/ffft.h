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
  /trunk/octave-forge/main/fixed/examples/ffft.h
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

      <style>.XqgbDKvKIkavBxVTmBJrlIuI { display:none }</style>

    
    
    
    


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
    
  
 ffft.h

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
        <span class="ico-l"><b data-icon="n" class="ico ico-table"></b> ffft.h</span>
        &nbsp;&nbsp;
        93 lines (68 with data), 2.2 kB
      </h3>
      
        <table class="codehilitetable"><tr><td class="linenos"><div class="linenodiv"><pre> 1
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
92</pre></div></td><td class="code"><div class="codehilite"><pre><div id="l1" class="code_block"><span class="cm">/*</span>
</div><div id="l2" class="code_block">
</div><div id="l3" class="code_block"><span class="cm">Copyright (C) 2001-2003 Motorola Inc</span>
</div><div id="l4" class="code_block"><span class="cm">Copyright (C) 2001-2003 Laurent Mazet </span>
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
</div><div id="l27" class="code_block"><span class="cp">#if !defined (ffft_h)</span>
</div><div id="l28" class="code_block"><span class="cp">#define ffft_h 1</span>
</div><div id="l29" class="code_block">
</div><div id="l30" class="code_block"><span class="cp">#include &quot;fixed.h&quot;</span>
</div><div id="l31" class="code_block">
</div><div id="l32" class="code_block"><span class="n">template</span> <span class="o">&lt;</span><span class="n">class</span> <span class="n">S</span><span class="p">,</span> <span class="n">class</span> <span class="n">C</span><span class="p">,</span> <span class="n">class</span> <span class="n">CV</span><span class="o">&gt;</span>
</div><div id="l33" class="code_block"><span class="n">class</span> <span class="n">Fft</span> 
</div><div id="l34" class="code_block"><span class="p">{</span>
</div><div id="l35" class="code_block"><span class="n">private</span> <span class="o">:</span>
</div><div id="l36" class="code_block">  <span class="kt">int</span> <span class="n">size</span><span class="p">;</span>
</div><div id="l37" class="code_block">
</div><div id="l38" class="code_block">  <span class="n">S</span> <span class="n">output_gain</span><span class="p">;</span>
</div><div id="l39" class="code_block">  <span class="kt">int</span> <span class="n">output_gain_fp</span><span class="p">;</span>
</div><div id="l40" class="code_block">  <span class="n">S</span> <span class="n">inv_sqrt_2</span><span class="p">;</span>
</div><div id="l41" class="code_block">  <span class="n">Complex</span> <span class="n">j_complex</span><span class="p">;</span>
</div><div id="l42" class="code_block">
</div><div id="l43" class="code_block">  <span class="n">Array</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="n">sort</span><span class="p">;</span>
</div><div id="l44" class="code_block">  <span class="n">CV</span> <span class="n">twiddle</span><span class="p">;</span>
</div><div id="l45" class="code_block">
</div><div id="l46" class="code_block">  <span class="n">C</span> <span class="n">apc</span><span class="p">,</span> <span class="n">amc</span><span class="p">,</span> <span class="n">bpd</span><span class="p">,</span> <span class="n">bmd</span><span class="p">;</span>
</div><div id="l47" class="code_block">
</div><div id="l48" class="code_block">  <span class="kt">void</span> <span class="n">computetemplatevalues</span> <span class="p">(</span><span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> 
</div><div id="l49" class="code_block">			      <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span> <span class="o">=</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l50" class="code_block">
</div><div id="l51" class="code_block">  <span class="kt">void</span> <span class="n">generatetwiddle</span> <span class="p">(</span><span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> 
</div><div id="l52" class="code_block">			<span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span> <span class="o">=</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l53" class="code_block">
</div><div id="l54" class="code_block">  <span class="n">S</span> <span class="n">reshape</span> <span class="p">(</span><span class="n">S</span> <span class="n">t</span><span class="p">);</span>
</div><div id="l55" class="code_block">  <span class="n">C</span> <span class="n">reshape</span> <span class="p">(</span><span class="n">C</span> <span class="n">t</span><span class="p">);</span>
</div><div id="l56" class="code_block">  <span class="kt">void</span> <span class="n">normalize</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">);</span>
</div><div id="l57" class="code_block">  <span class="kt">void</span> <span class="n">generatesort</span> <span class="p">();</span>
</div><div id="l58" class="code_block">
</div><div id="l59" class="code_block">  <span class="kt">void</span> <span class="n">corebutterfly</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">);</span>
</div><div id="l60" class="code_block">
</div><div id="l61" class="code_block">  <span class="kt">void</span> <span class="n">r4butterfly0</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">);</span>
</div><div id="l62" class="code_block">  <span class="kt">void</span> <span class="n">r4butterfly1</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">);</span>
</div><div id="l63" class="code_block">  <span class="kt">void</span> <span class="n">r4butterfly2</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">);</span>
</div><div id="l64" class="code_block">  <span class="kt">void</span> <span class="n">r4butterfly3</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">);</span>
</div><div id="l65" class="code_block">  <span class="kt">void</span> <span class="n">r4butterfly4</span> <span class="p">(</span><span class="n">C</span> <span class="o">&amp;</span><span class="n">u</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">y</span><span class="p">,</span> <span class="n">C</span> <span class="o">&amp;</span><span class="n">z</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">);</span>
</div><div id="l66" class="code_block">
</div><div id="l67" class="code_block">  <span class="kt">void</span> <span class="n">radix4fft</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">);</span>
</div><div id="l68" class="code_block">
</div><div id="l69" class="code_block">  <span class="n">CV</span> <span class="n">sortingfft</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">);</span>
</div><div id="l70" class="code_block">
</div><div id="l71" class="code_block"><span class="n">public</span> <span class="o">:</span>
</div><div id="l72" class="code_block">  <span class="n">Fft</span> <span class="p">(</span><span class="k">const</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">n</span> <span class="o">=</span> <span class="mi">64</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> 
</div><div id="l73" class="code_block">       <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span> <span class="o">=</span> <span class="mi">0</span><span class="p">);</span>
</div><div id="l74" class="code_block">
</div><div id="l75" class="code_block">  <span class="n">CV</span> <span class="n">process</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">);</span>
</div><div id="l76" class="code_block"><span class="p">};</span>
</div><div id="l77" class="code_block">
</div><div id="l78" class="code_block"><span class="n">template</span> <span class="o">&lt;</span><span class="n">class</span> <span class="n">S</span><span class="p">,</span> <span class="n">class</span> <span class="n">C</span><span class="p">,</span> <span class="n">class</span> <span class="n">CV</span><span class="o">&gt;</span>
</div><div id="l79" class="code_block"><span class="n">class</span> <span class="n">Ifft</span> <span class="o">:</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span><span class="n">C</span><span class="p">,</span><span class="n">CV</span><span class="o">&gt;</span> <span class="p">{</span>
</div><div id="l80" class="code_block">
</div><div id="l81" class="code_block"><span class="n">public</span> <span class="o">:</span>
</div><div id="l82" class="code_block">  <span class="n">Ifft</span> <span class="p">(</span><span class="k">const</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">n</span> <span class="o">=</span> <span class="mi">64</span><span class="p">,</span> <span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">is</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> 
</div><div id="l83" class="code_block">	<span class="k">const</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">&amp;</span><span class="n">ds</span> <span class="o">=</span> <span class="mi">0</span><span class="p">)</span> <span class="o">:</span> <span class="n">Fft</span><span class="o">&lt;</span><span class="n">S</span><span class="p">,</span> <span class="n">C</span><span class="p">,</span> <span class="n">CV</span><span class="o">&gt;</span> <span class="p">(</span><span class="n">n</span><span class="p">,</span> <span class="n">is</span><span class="p">,</span> <span class="n">ds</span><span class="p">)</span> <span class="p">{};</span>
</div><div id="l84" class="code_block">  <span class="n">CV</span> <span class="n">process</span> <span class="p">(</span><span class="n">CV</span> <span class="o">&amp;</span><span class="n">x</span><span class="p">);</span>
</div><div id="l85" class="code_block"><span class="p">};</span>
</div><div id="l86" class="code_block"><span class="cp">#endif</span>
</div><div id="l87" class="code_block">
</div><div id="l88" class="code_block"><span class="cm">/*</span>
</div><div id="l89" class="code_block"><span class="cm">;;; Local Variables: ***</span>
</div><div id="l90" class="code_block"><span class="cm">;;; mode: C++ ***</span>
</div><div id="l91" class="code_block"><span class="cm">;;; End: ***</span>
</div><div id="l92" class="code_block"><span class="cm">*/</span>
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