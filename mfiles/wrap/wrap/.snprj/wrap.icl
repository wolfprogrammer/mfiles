b1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ( �l���T8�$nal.H
WishHandler.H
Octawrap.C
Thread.H
WishHandler.C
wrap.C
Thread.C
 t symbr $itk_component(hull).symbr

        on_close "$itk_component(hull) windows_close dummy"
        #don't close window by hitting Escape
      #  ${this} bind_tk <Escape> {;}

        withdraw

        if {${x} != ""} {
            wm geometry  $itk_component(hull) [expr int(${width})]x[expr int(${height})]+${x}+${y}
        } else {
            set height [expr {int([winfo screenheight .] *
                ($sn_options(def,window-size)*0.01))}]
            set width [expr {int([winfo screenwidth .] / 3)}]
            if {${width} < 300} {
                set width 300
            } elseif {${width} > 450} {
                set width 450
            }
            wm geometry $itk_component(hull) ${width}x${height}
        }

        set Toolbar $itk_component(hull).exp
        set Statusbar $itk_component(hull).msg

        AddMenu
        AddToolbar
        AddStatusbar

        $itk_component(hull).menu configure -font $sn_options(def,layout-font)

        Retr& ${symbr}  -symbols ""  -symbols_filter ""  -menu "$itk_component(hull).menu"  -toolbar "${Toolbar}"  -mesg_area ""  -height ${height}  -width ${width}  -mode symbr  -restore ${restore}  -selectcommand "${this} handle_select"  -parent ${this}
        pack ${symbr} -expand y -fill both -side left

        ${symbr} SetTitle

        after idle "window_configure $itk_component(hull) deiconify [${symbr}.list tree]"

        #call user function
        catch {sn_rc_symbolbrowser $itk_component(hull)  $itk_component(hull).menu}
    }
    destructor {
        foreach v [::info globals "${this}-*"] {
            catch {uplevel #0 unset ${v}}
        }
    }
    method config {config} {
    }
    method AddToolbar {} {
        set exp ${Toolbar}
        frame ${Toolbar} -relief groove -border 2
        pack ${Toolbar} -side top -fill x

        #Hierarchy
        button ${exp}.tree -takefocus 0 -image tree_image -command "${this} run_ctree" -state disabled
        bind_history ${exp}.tree tree
        balloon_bind_info ${exp}.tree [get_indep String INFOHierarchy]
        pack ${exp}.tree -side left

        #Class
        button ${exp}.class -takefocus 0 -image watch_image -command "${this} run_class" -state disabled
        bind_history ${exp}.class browse
        balloon_bind_info ${exp}.class [get_indep String INFOStartClassBrw]
        pack ${exp}.class -side left

        #Xref
        button ${exp}.xref -takefocus 0 -image crossref_image -command " ${this} run_xref " -state disabled
        bind_history ${exp}.xref xref
        balloon_bind_info ${exp}.xref [get_indep String StartXRefINFO]
        pack ${exp}.xref -side left

        #Include
        button ${exp}.inc -takefocus 0 -image include_image -command "${this} run_include" -state disabled
        balloon_bind_info ${exp}.inc [get_indep String IncludeLaunch]
        pack ${exp}.inc -side left

        pack [frame ${exp}.space -width 7] -side left
    }
    method AddStatusbar {} {
        global sn_options
        frame ${Statusbar}
        pack [label ${Statusbar}.msg -font $sn_options(def,layout-font) -relief groove -bd 2 -anchor w -textvar ${this}.msg] -expand y -fill both -side left
        pack ${Statusbar} -side bottom -fill x
    }

    method handle_select {{scope ""} {sym ""} {cls ""} {file ""} {from ""} {type ""} {prm ""} {to ""} {always 1}} {
        if {${scope} == "cl"} {
            set cls ${sym}
        }
        if {${cls} != "" && ${scope} != "cov"} {
            set class_state normal
        } else {
            set class_state disabled
        }
        if {${file} != ""} {
            set inc_state [tool_Exists incbr]
        } else {
            set inc_state disabled
        }
        set xref_state [tool_Exists xref]
        if {       Thread.C. # _s	       wrap.C. #        WishHandler.C. #         Thread.H. #          Octawrap.C. #        WishHandler.H. #         Terminal.H. #        Terminal.C. #        Octawrap.H. #        Makefile. # ta