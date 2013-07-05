	;; -*- lexical-binding: t -*-
;;(require 'w3m-load)
;;(require 'mime-w3m)

;;(require 'eide)
;;(eide-start)


(require 'ido)
(ido-mode t)
'(ido-enable-flex-matching t)



;; Shift-F6/f3 stores a position in a file, F6/f3 brings you back to this position
(global-set-key [(shift f2)] '(lambda () (interactive) (point-to-register ?1)))
(global-set-key [f2] '(lambda () (interactive) (register-to-point ?1)))
(global-set-key [(shift f3)] '(lambda () (interactive) (point-to-register ?2)))
(global-set-key [f3] '(lambda () (interactive) (register-to-point ?2)))    

;; recentf - F5
(require 'recentf)
(recentf-mode 1)
(setq recentf-max-saved-items 500)
(setq recentf-max-menu-items 60)
(global-set-key [f5] 'recentf-open-files)
(defun xsteve-ido-choose-from-recentf ()
  "Use ido to select a recently opened file from the `recentf-list'"
  (interactive)
  (let ((home (expand-file-name (getenv "HOME"))))
    (find-file
     (ido-completing-read "Recentf open: "
                          (mapcar (lambda (path)
                                    (replace-regexp-in-string home "~" path))
                                  recentf-list)
                          nil t))))    



;;----------- Start with bookmarks------------------ ;;
(setq inhibit-splash-screen t)
(require 'bookmark)
(bookmark-bmenu-list)
(switch-to-buffer "*Bookmark List*")



;; We set a key-binding for this often-used command:
(global-set-key [f12] 'compile)

;; If we read a compressed file, uncompress it on the fly:
;; (this works with .tar.gz and .tgz file as well)  
(auto-compression-mode 1)

;;; Shut up compile saves
(setq compilation-ask-about-save nil)
;;; Don't save *anything*
(setq compilation-save-buffers-predicate '(lambda () nil))


(global-set-key [C-tab] "\C-q\t")	; Control tab quotes a tab.

;;  Switch to Buffer menu
(global-set-key [f6] 'buffer-menu)

(global-font-lock-mode t)              ; always highlight source code
(blink-cursor-mode -1)                 ; make cursor not blink


(load-file "~/.emacs.d/smart-compile.el")
(require 'smart-compile)

;;(require 'smarter-compile)
;; (add-to-list
;;   'smart-compile-alist
;;   '("\\.css\\'"   .   "/bin/csslint.js --format=compiler %f"))
;;(provide 'init-smarter-compile)


;;-------------------  cscope -------------------- ;;
(setq cscope-do-not-update-database t)
(load-file "/usr/share/emacs/site-lisp/xcscope.el")
(require 'xcscope)



;;=====================================



;(add-to-list 'load-path
              ;"~/.emacs.d/plugins/yasnippet")
;(require 'yasnippet)
;(yas-global-mode 1)    



(setq load-path (cons (expand-file-name "~/.emacs.d/lisp") load-path))
(require 'template)
(template-initialize)


;; Disable all the version control stuff         
;; Makes emacs load much faster inside git repos 
 
(setq vc-handled-backends nil)



;; ===== Enable mouse support ====
                                       
(require 'xt-mouse)                   
(xterm-mouse-mode)    
;; Mouse menu
(global-set-key [mouse-3] 'imenu)



;;======= EMACS BEHAVIOR ================= ;;
;; show matching parens
(show-paren-mode 1)

;; always show column numbers
(column-number-mode 1)

;; Narrow (C-x n n)
(put 'narrow-to-region 'disabled nil)

;; take the short answer, y/n is yes/no
(defalias 'yes-or-no-p 'y-or-n-p)    

;;--- RECENT FILES
(recentf-mode 1)
(global-set-key (kbd "C-x C-r") 'recentf-open-files)    


;; Save backup files
;; 
;; If you've ever had your ass saved by an Emacs 
;; backup file, you probably want more of them,    
;;
(setq backup-directory-alist `(("." . "~/.emacs.d/backup")))    
(setq backup-by-copying t)    
(setq delete-old-versions t
  kept-new-versions 6
  kept-old-versions 2
  version-control t)    



;====== Speed Bar ======================== ;;
;; (speedbar 1)    



;======= Change Background Color ========== ;;
;; Set cursor and mouse-pointer colours
(set-cursor-color "red")
(set-mouse-color "goldenrod")

;; Set region background colour
(set-face-background 'region "blue")

;; Set emacs background colour
(set-background-color "black")    

(set-background-color "black")
(set-face-background 'default "black")
(set-face-background 'region "black")
(set-face-foreground 'default "white")
(set-face-foreground 'region "gray60")
(set-foreground-color "white")
(set-cursor-color "red")    


;=========== Show Line Number============== ;;
(require 'linum)
(global-linum-mode t)

;========== Show Nav Bar ================== ;;
(add-to-list 'load-path "~/.emacs.d/nav")
(require 'nav)
(nav-disable-overeager-window-splitting)
;; Optional: set up a quick key to toggle nav
(global-set-key [f8] 'nav-toggle)
    

;;========= eproject ======================;;
;; (load-file "~/emacs.d/eprojects/eproject.el")
    

;;========== BOOKMARKS ===================  ;;

;;(setq inhibit-splash-screen t)
;;(require 'bookmark)
;;(bookmark-bmenu-list)
;;(switch-to-buffer "*Bookmark List*")    

;;========== VIM MODE - EVIL ============== ;;

(add-to-list 'load-path "~/.emacs.d/undo-tree")   
(load-file "~/.emacs.d/undo-tree.el")
( global-undo-tree-mode )


;(require 'undo-tree)    
;(global-undo-tree-mode)    

;(require 'undo-tree)
;(global-undo-tree-mode 1) 
(add-to-list 'load-path "~/.emacs.d/evil")
(require 'evil)  
(evil-mode 1)


(load "elscreen" "ElScreen" t)
(define-key evil-normal-state-map (kbd "C-w t") 'elscreen-create) ;creat tab
(define-key evil-normal-state-map (kbd "C-w x") 'elscreen-kill) ;kill tab
(define-key evil-normal-state-map "gT" 'elscreen-previous) ;previous tab
(define-key evil-normal-state-map "gt" 'elscreen-next) ;next tab  


;;=========== TEMPLATE ================= ;;

;(add-to-list 'load-path "~/.emacs.d/template-menu/")
;(load-file "~/.emacs.d/template-menu/templ-menu.el")  
;(require 'template)
;(template-initialize)
;( template-menu-build-menu-from-dir "~/.emacs.d/template-menu/example-templates" )

    








(defvar HOME (expand-file-name "~"))

;; ------
;; FORTH
;; ------
(defvar GFORTH_EL (concat HOME "~/.emacs.d/gforth.el"))
(cond ((file-readable-p GFORTH_EL)
  (load-library GFORTH_EL)
  (autoload 'forth-mode GFORTH_EL)
  (setq auto-mode-alist (cons '("\\.fs\\'" . forth-mode) auto-mode-alist))
  (autoload 'forth-block-mode GFORTH_EL)
  (setq auto-mode-alist (cons '("\\.fb\\'" . forth-block-mode) auto-mode-alist))
  (add-hook 'forth-mode-hook (function (lambda ()
    (setq forth-indent-level 4)
    (setq forth-minor-indent-level 2)
    (setq forth-hilight-level 3))))
))

;;========== OCTAVE ====================

(autoload 'octave-mode "octave-mod" nil t)
(setq auto-mode-alist
(cons '("\\.m$" . octave-mode) auto-mode-alist))

(add-hook 'octave-mode-hook
(lambda ()
(abbrev-mode 1)
(auto-fill-mode 1)
(if (eq window-system 'x)
(font-lock-mode 1))))    

(defun RET-behaves-as-LFD ()
  (let ((x (key-binding "\C-j")))
    (local-set-key "\C-m" x)))
(add-hook 'octave-mode-hook 'RET-behaves-as-LFD)

(setq octave-auto-indent t)

     

;;============ GIT ====================

(add-to-list 'load-path "~/.emacs.d/git-emacs" t)
(require 'git-emacs)

;;======== PYTHON =============== ;;


;;======== CUSTOM MENU =========== ;;

(easy-menu-define djcb-menu global-map "Utilities"
  '("Utilities"
     ;; http://emacs-fu.blogspot.com/2008/12/running-console-programs-inside-emacs.html
     ("Shell" ;; submenu
       ["Bash shell : shell"  	    ( shell )]
       ["Eshell : eshell"  	   ( eshell )]
       ["Terminal emulator: term"   ( term "/bin/bash"  )]
       ["Forth:  run-forth"   ( run-gforth )]
       ["Python: run-python"  ( run-python )]
       ["Octave: run-octave"  ( run-octave)])

     
     
     ;; http://emacs-fu.blogspot.com/2009/03/twitter.html
     ("Functions" ;; submenu
       ["Eval buffer"   ( eval-buffer ) ]
       ["Emacs command history "   ( list-command-history ) ]
       ["GNU MAN pages" ( info 	      )   ]
       ["Describe key"  ( describe-key )  ]
       )

     ("Tool set"  ;; submenu
       ["Generate TAGS" ( shell-command "$HOME/bin/scope.sh" ) ]
       [ "Download firmware : make download " ( shell-command "make download" ) ]

       ;; http://emacs-fu.blogspot.com/2008/12/running-emacs-in-full-screen-mode.html
       ["Toggle full-screen" djcb-fullscreen-toggle])
)
)    





;; Highlight numbers
;;
;;
(add-hook 'c-mode-common-hook (lambda ()
    (font-lock-add-keywords nil '(

        ; Valid hex number (will highlight invalid suffix though)
        ("\\b0x[[:xdigit:]]+[uUlL]*\\b" . font-lock-string-face)

        ; Invalid hex number
        ("\\b0x\\(\\w\\|\\.\\)+\\b" . font-lock-warning-face)

        ; Valid floating point number.
        ("\\(\\b[0-9]+\\|\\)\\(\\.\\)\\([0-9]+\\(e[-]?[0-9]+\\)?\\([lL]?\\|[dD]?[fF]?\\)\\)\\b" (1 font-lock-string-face) (3 font-lock-string-face))

        ; Invalid floating point number.  Must be before valid decimal.
        ("\\b[0-9].*?\\..+?\\b" . font-lock-warning-face)

        ; Valid decimal number.  Must be before octal regexes otherwise 0 and 0l
        ; will be highlighted as errors.  Will highlight invalid suffix though.
        ("\\b\\(\\(0\\|[1-9][0-9]*\\)[uUlL]*\\)\\b" 1 font-lock-string-face)

        ; Valid octal number
        ("\\b0[0-7]+[uUlL]*\\b" . font-lock-string-face)

        ; Floating point number with no digits after the period.  This must be
        ; after the invalid numbers, otherwise it will "steal" some invalid
        ; numbers and highlight them as valid.
        ("\\b\\([0-9]+\\)\\." (1 font-lock-string-face))

        ; Invalid number.  Must be last so it only highlights anything not
        ; matched above.
        ("\\b[0-9]\\(\\w\\|\\.\\)+?\\b" . font-lock-warning-face)
    ))
))    


;; Add the following code to your .emacs:
(add-to-list 'load-path "~/.emacs.d/")
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/ac-dict")
(ac-config-default)
                               
(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(safe-local-variable-values (quote ((lexical-binding . t)))))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )



;; Choose not warn of local Varibales list 
(custom-set-variables
 '(safe-local-variable-values (quote ((clmemo-mode . t)))))

