<!DOCTYPE html>
<!-- Server: sfn-web-2 -->


  










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
  /trunk/octave-forge/main/fixed/src/ov-base-fixed-mat.cc
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

      <style>.XgxJordAgKKvEmGrPxzTY { display:none }</style>

    
    
    
    


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
    
  
 ov-base-fixed-mat.cc

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
        <span class="ico-l"><b data-icon="n" class="ico ico-table"></b> ov-base-fixed-mat.cc</span>
        &nbsp;&nbsp;
        190 lines (152 with data), 4.1 kB
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
189</pre></div></td><td class="code"><div class="codehilite"><pre><div id="l1" class="code_block"><span class="cm">/*</span>
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
</div><div id="l26" class="code_block"><span class="cp">#include &lt;config.h&gt;</span>
</div><div id="l27" class="code_block"><span class="cp">#include &lt;iostream&gt;</span>
</div><div id="l28" class="code_block"><span class="cp">#include &lt;octave/oct-obj.h&gt;</span>
</div><div id="l29" class="code_block"><span class="cp">#include &lt;octave/ov-base.h&gt;</span>
</div><div id="l30" class="code_block"><span class="cp">#include &lt;octave/ov-base-scalar.h&gt;</span>
</div><div id="l31" class="code_block"><span class="cp">#include &lt;octave/pr-output.h&gt;</span>
</div><div id="l32" class="code_block">
</div><div id="l33" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l34" class="code_block"><span class="n">octave_value_list</span>
</div><div id="l35" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">dotref</span> <span class="p">(</span><span class="k">const</span> <span class="n">octave_value_list</span><span class="o">&amp;</span> <span class="n">idx</span><span class="p">)</span>
</div><div id="l36" class="code_block"><span class="p">{</span>
</div><div id="l37" class="code_block">  <span class="n">octave_value_list</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l38" class="code_block">
</div><div id="l39" class="code_block">  <span class="n">assert</span> <span class="p">(</span><span class="n">idx</span><span class="p">.</span><span class="n">length</span> <span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">);</span>
</div><div id="l40" class="code_block">
</div><div id="l41" class="code_block">  <span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">nm</span> <span class="o">=</span> <span class="n">idx</span><span class="p">(</span><span class="mi">0</span><span class="p">).</span><span class="n">string_value</span> <span class="p">();</span>
</div><div id="l42" class="code_block">
</div><div id="l43" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">nm</span> <span class="o">==</span> <span class="n">__FIXED_SIGN_STR</span><span class="p">)</span>
</div><div id="l44" class="code_block">    <span class="n">retval</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="o">=</span> <span class="n">octave_value</span> <span class="p">(</span><span class="n">matrix</span><span class="p">.</span><span class="n">sign</span><span class="p">());</span>
</div><div id="l45" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nm</span> <span class="o">==</span> <span class="n">__FIXED_VALUE_STR</span><span class="p">)</span> 
</div><div id="l46" class="code_block">    <span class="n">retval</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="o">=</span> <span class="n">octave_value</span> <span class="p">(</span><span class="n">matrix</span><span class="p">.</span><span class="n">fixedpoint</span><span class="p">());</span>
</div><div id="l47" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nm</span> <span class="o">==</span> <span class="n">__FIXED_DECSIZE_STR</span><span class="p">)</span>
</div><div id="l48" class="code_block">    <span class="n">retval</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="o">=</span> <span class="n">octave_value</span> <span class="p">(</span><span class="n">matrix</span><span class="p">.</span><span class="n">getdecsize</span><span class="p">());</span>
</div><div id="l49" class="code_block">  <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">nm</span> <span class="o">==</span> <span class="n">__FIXED_INTSIZE_STR</span><span class="p">)</span>
</div><div id="l50" class="code_block">    <span class="n">retval</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="o">=</span> <span class="n">octave_value</span> <span class="p">(</span><span class="n">matrix</span><span class="p">.</span><span class="n">getintsize</span><span class="p">());</span>
</div><div id="l51" class="code_block">  <span class="k">else</span>
</div><div id="l52" class="code_block">    <span class="n">error</span> <span class="p">(</span><span class="s">&quot;fixed point structure has no member `%s&#39;&quot;</span><span class="p">,</span> <span class="n">nm</span><span class="p">.</span><span class="n">c_str</span> <span class="p">());</span>    
</div><div id="l53" class="code_block">
</div><div id="l54" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l55" class="code_block"><span class="p">}</span>
</div><div id="l56" class="code_block">
</div><div id="l57" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l58" class="code_block"><span class="n">octave_value</span>
</div><div id="l59" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">subsref</span> <span class="p">(</span><span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span><span class="o">&amp;</span> <span class="n">type</span><span class="p">,</span>
</div><div id="l60" class="code_block">				 <span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">list</span><span class="o">&lt;</span><span class="n">octave_value_list</span><span class="o">&gt;&amp;</span> <span class="n">idx</span><span class="p">)</span>
</div><div id="l61" class="code_block"><span class="p">{</span>
</div><div id="l62" class="code_block">  <span class="n">octave_value</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l63" class="code_block">
</div><div id="l64" class="code_block">  <span class="k">switch</span> <span class="p">(</span><span class="n">type</span><span class="p">[</span><span class="mi">0</span><span class="p">])</span>
</div><div id="l65" class="code_block">    <span class="p">{</span>
</div><div id="l66" class="code_block">    <span class="k">case</span> <span class="sc">&#39;(&#39;</span><span class="o">:</span>
</div><div id="l67" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="n">do_index_op</span> <span class="p">(</span><span class="n">idx</span><span class="p">.</span><span class="n">front</span> <span class="p">());</span>
</div><div id="l68" class="code_block">      <span class="k">break</span><span class="p">;</span>
</div><div id="l69" class="code_block">
</div><div id="l70" class="code_block">    <span class="k">case</span> <span class="sc">&#39;.&#39;</span><span class="o">:</span>
</div><div id="l71" class="code_block">      <span class="p">{</span>
</div><div id="l72" class="code_block">	<span class="n">octave_value_list</span> <span class="n">t</span> <span class="o">=</span> <span class="n">dotref</span> <span class="p">(</span><span class="n">idx</span><span class="p">.</span><span class="n">front</span> <span class="p">());</span>
</div><div id="l73" class="code_block">
</div><div id="l74" class="code_block">	<span class="n">retval</span> <span class="o">=</span> <span class="p">(</span><span class="n">t</span><span class="p">.</span><span class="n">length</span> <span class="p">()</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="o">?</span> <span class="n">t</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="o">:</span> <span class="n">octave_value</span> <span class="p">(</span><span class="n">t</span><span class="p">);</span>
</div><div id="l75" class="code_block">      <span class="p">}</span>
</div><div id="l76" class="code_block">      <span class="k">break</span><span class="p">;</span>
</div><div id="l77" class="code_block">
</div><div id="l78" class="code_block">    <span class="k">case</span> <span class="sc">&#39;{&#39;</span><span class="o">:</span>
</div><div id="l79" class="code_block">      <span class="p">{</span>
</div><div id="l80" class="code_block">	<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">nm</span> <span class="o">=</span> <span class="n">type_name</span> <span class="p">();</span>
</div><div id="l81" class="code_block">	<span class="n">error</span> <span class="p">(</span><span class="s">&quot;%s cannot be indexed with %c&quot;</span><span class="p">,</span> <span class="n">nm</span><span class="p">.</span><span class="n">c_str</span> <span class="p">(),</span> <span class="n">type</span><span class="p">[</span><span class="mi">0</span><span class="p">]);</span>
</div><div id="l82" class="code_block">      <span class="p">}</span>
</div><div id="l83" class="code_block">      <span class="k">break</span><span class="p">;</span>
</div><div id="l84" class="code_block">
</div><div id="l85" class="code_block">    <span class="k">default</span><span class="o">:</span>
</div><div id="l86" class="code_block">      <span class="n">panic_impossible</span> <span class="p">();</span>
</div><div id="l87" class="code_block">    <span class="p">}</span>
</div><div id="l88" class="code_block">
</div><div id="l89" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">.</span><span class="n">next_subsref</span> <span class="p">(</span><span class="n">type</span><span class="p">,</span> <span class="n">idx</span><span class="p">);</span>
</div><div id="l90" class="code_block"><span class="p">}</span>
</div><div id="l91" class="code_block">
</div><div id="l92" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l93" class="code_block"><span class="kt">void</span>
</div><div id="l94" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">assign</span> <span class="p">(</span><span class="k">const</span> <span class="n">octave_value_list</span><span class="o">&amp;</span> <span class="n">idx</span><span class="p">,</span> 
</div><div id="l95" class="code_block">				      <span class="k">const</span> <span class="n">MT</span><span class="o">&amp;</span> <span class="n">rhs</span><span class="p">)</span>
</div><div id="l96" class="code_block"><span class="p">{</span>
</div><div id="l97" class="code_block">  <span class="kt">int</span> <span class="n">len</span> <span class="o">=</span> <span class="n">idx</span><span class="p">.</span><span class="n">length</span> <span class="p">();</span>
</div><div id="l98" class="code_block">
</div><div id="l99" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">len</span> <span class="o">&gt;</span> <span class="mi">2</span><span class="p">)</span>
</div><div id="l100" class="code_block">      <span class="n">error</span> <span class="p">(</span><span class="s">&quot;invalid number of indices (%d) for indexed assignment&quot;</span><span class="p">,</span>
</div><div id="l101" class="code_block">	     <span class="n">len</span><span class="p">);</span>
</div><div id="l102" class="code_block">  <span class="k">else</span>
</div><div id="l103" class="code_block">    <span class="p">{</span>
</div><div id="l104" class="code_block">      <span class="n">Array</span><span class="o">&lt;</span><span class="n">idx_vector</span><span class="o">&gt;</span> <span class="n">ra_idx</span> <span class="p">(</span><span class="n">dim_vector</span> <span class="p">(</span><span class="n">len</span><span class="p">,</span> <span class="mi">1</span><span class="p">));</span>
</div><div id="l105" class="code_block">
</div><div id="l106" class="code_block">      <span class="k">for</span> <span class="p">(</span><span class="n">octave_idx_type</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">len</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
</div><div id="l107" class="code_block">	<span class="n">ra_idx</span><span class="p">(</span><span class="n">i</span><span class="p">)</span> <span class="o">=</span> <span class="n">idx</span><span class="p">(</span><span class="n">i</span><span class="p">).</span><span class="n">index_vector</span> <span class="p">();</span>
</div><div id="l108" class="code_block">
</div><div id="l109" class="code_block">      <span class="n">matrix</span><span class="p">.</span><span class="n">assign</span> <span class="p">(</span><span class="n">ra_idx</span><span class="p">,</span> <span class="n">rhs</span><span class="p">,</span> <span class="n">FixedPoint</span> <span class="p">());</span>
</div><div id="l110" class="code_block">    <span class="p">}</span>
</div><div id="l111" class="code_block"><span class="p">}</span>
</div><div id="l112" class="code_block">
</div><div id="l113" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l114" class="code_block"><span class="kt">bool</span>
</div><div id="l115" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">is_true</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l116" class="code_block"><span class="p">{</span>
</div><div id="l117" class="code_block">  <span class="kt">bool</span> <span class="n">retval</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l118" class="code_block">
</div><div id="l119" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">rows</span> <span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">columns</span> <span class="p">()</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>
</div><div id="l120" class="code_block">    <span class="p">{</span>
</div><div id="l121" class="code_block">      <span class="n">boolMatrix</span> <span class="n">m</span> <span class="o">=</span> <span class="p">(</span><span class="n">matrix</span><span class="p">.</span><span class="n">all</span> <span class="p">()</span> <span class="p">.</span> <span class="n">all</span> <span class="p">());</span>
</div><div id="l122" class="code_block">
</div><div id="l123" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="p">(</span><span class="n">m</span><span class="p">.</span><span class="n">rows</span> <span class="p">()</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">&amp;&amp;</span> <span class="n">m</span><span class="p">.</span><span class="n">columns</span> <span class="p">()</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">&amp;&amp;</span> <span class="n">m</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">));</span>
</div><div id="l124" class="code_block">    <span class="p">}</span>
</div><div id="l125" class="code_block">
</div><div id="l126" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l127" class="code_block"><span class="p">}</span>
</div><div id="l128" class="code_block">
</div><div id="l129" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l130" class="code_block"><span class="kt">bool</span>
</div><div id="l131" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">valid_as_scalar_index</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l132" class="code_block"><span class="p">{</span>
</div><div id="l133" class="code_block">  <span class="c1">// XXX FIXME XXX</span>
</div><div id="l134" class="code_block">  <span class="k">return</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l135" class="code_block"><span class="p">}</span>
</div><div id="l136" class="code_block">
</div><div id="l137" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l138" class="code_block"><span class="kt">bool</span>
</div><div id="l139" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">print_as_scalar</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l140" class="code_block"><span class="p">{</span>
</div><div id="l141" class="code_block">  <span class="kt">int</span> <span class="n">nr</span> <span class="o">=</span> <span class="n">rows</span> <span class="p">();</span>
</div><div id="l142" class="code_block">  <span class="kt">int</span> <span class="n">nc</span> <span class="o">=</span> <span class="n">columns</span> <span class="p">();</span>
</div><div id="l143" class="code_block">
</div><div id="l144" class="code_block">  <span class="k">return</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">&amp;&amp;</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">1</span> <span class="o">||</span> <span class="p">(</span><span class="n">nr</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">||</span> <span class="n">nc</span> <span class="o">==</span> <span class="mi">0</span><span class="p">));</span>
</div><div id="l145" class="code_block"><span class="p">}</span>
</div><div id="l146" class="code_block">
</div><div id="l147" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l148" class="code_block"><span class="kt">void</span>
</div><div id="l149" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">print</span> <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">ostream</span><span class="o">&amp;</span> <span class="n">os</span><span class="p">,</span> <span class="kt">bool</span> <span class="n">pr_as_read_syntax</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l150" class="code_block"><span class="p">{</span>
</div><div id="l151" class="code_block">  <span class="n">print_raw</span> <span class="p">(</span><span class="n">os</span><span class="p">,</span> <span class="n">pr_as_read_syntax</span><span class="p">);</span>
</div><div id="l152" class="code_block">  <span class="n">newline</span> <span class="p">(</span><span class="n">os</span><span class="p">);</span>
</div><div id="l153" class="code_block"><span class="p">}</span>
</div><div id="l154" class="code_block">
</div><div id="l155" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l156" class="code_block"><span class="kt">bool</span>
</div><div id="l157" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">print_name_tag</span> <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">ostream</span><span class="o">&amp;</span> <span class="n">os</span><span class="p">,</span>
</div><div id="l158" class="code_block">					<span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span><span class="o">&amp;</span> <span class="n">name</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l159" class="code_block"><span class="p">{</span>
</div><div id="l160" class="code_block">  <span class="kt">bool</span> <span class="n">retval</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
</div><div id="l161" class="code_block">
</div><div id="l162" class="code_block">  <span class="n">indent</span> <span class="p">(</span><span class="n">os</span><span class="p">);</span>
</div><div id="l163" class="code_block">
</div><div id="l164" class="code_block">  <span class="k">if</span> <span class="p">(</span><span class="n">print_as_scalar</span> <span class="p">())</span>
</div><div id="l165" class="code_block">    <span class="n">os</span> <span class="o">&lt;&lt;</span> <span class="n">name</span> <span class="o">&lt;&lt;</span> <span class="s">&quot; = &quot;</span><span class="p">;</span>
</div><div id="l166" class="code_block">  <span class="k">else</span>
</div><div id="l167" class="code_block">    <span class="p">{</span>
</div><div id="l168" class="code_block">      <span class="n">os</span> <span class="o">&lt;&lt;</span> <span class="n">name</span> <span class="o">&lt;&lt;</span> <span class="s">&quot; =&quot;</span><span class="p">;</span>
</div><div id="l169" class="code_block">      <span class="n">newline</span> <span class="p">(</span><span class="n">os</span><span class="p">);</span>
</div><div id="l170" class="code_block">      <span class="n">newline</span> <span class="p">(</span><span class="n">os</span><span class="p">);</span>
</div><div id="l171" class="code_block">      <span class="n">retval</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
</div><div id="l172" class="code_block">    <span class="p">}</span>
</div><div id="l173" class="code_block">
</div><div id="l174" class="code_block">  <span class="k">return</span> <span class="n">retval</span><span class="p">;</span>
</div><div id="l175" class="code_block"><span class="p">}</span>
</div><div id="l176" class="code_block">
</div><div id="l177" class="code_block"><span class="k">template</span> <span class="o">&lt;</span><span class="k">class</span> <span class="nc">MT</span><span class="o">&gt;</span>
</div><div id="l178" class="code_block"><span class="kt">void</span>
</div><div id="l179" class="code_block"><span class="n">octave_base_fixed_matrix</span><span class="o">&lt;</span><span class="n">MT</span><span class="o">&gt;::</span><span class="n">print_info</span> <span class="p">(</span><span class="n">std</span><span class="o">::</span><span class="n">ostream</span><span class="o">&amp;</span> <span class="n">os</span><span class="p">,</span>
</div><div id="l180" class="code_block">				    <span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span><span class="o">&amp;</span> <span class="n">prefix</span><span class="p">)</span> <span class="k">const</span>
</div><div id="l181" class="code_block"><span class="p">{</span>
</div><div id="l182" class="code_block">  <span class="n">matrix</span><span class="p">.</span><span class="n">print_info</span> <span class="p">(</span><span class="n">os</span><span class="p">,</span> <span class="n">prefix</span><span class="p">);</span>
</div><div id="l183" class="code_block"><span class="p">}</span>
</div><div id="l184" class="code_block">
</div><div id="l185" class="code_block"><span class="cm">/*</span>
</div><div id="l186" class="code_block"><span class="cm">;;; Local Variables: ***</span>
</div><div id="l187" class="code_block"><span class="cm">;;; mode: C++ ***</span>
</div><div id="l188" class="code_block"><span class="cm">;;; End: ***</span>
</div><div id="l189" class="code_block"><span class="cm">*/</span>
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