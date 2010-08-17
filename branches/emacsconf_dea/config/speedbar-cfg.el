;; -*- coding: utf-8 mode: Emacs-Lisp -*-
;; speedbar-cfg.el --- 
;; Time-stamp: <2010-01-28 18:12:49 julian>
;; Created: 2010 Julian Qian
;; Version: $Id: speedbar-cfg.el,v 0.0 2010/01/28 10:11:58 julian Exp $

;; 

;;; Code:
;; (eval-when-compile (require 'cl))

(require 'speedbar)

(setq speedbar-update-speed 3)
(setq speedbar-use-images t)

(defvar my-speedbar-buffer-name 
  (if (buffer-live-p speedbar-buffer)
      (buffer-name speedbar-buffer)
    "*SpeedBar*"))

;; Speedbar within frame
(defun my-speedbar-no-separate-frame ()
  (interactive)
  (when (not (buffer-live-p speedbar-buffer))
    (setq speedbar-buffer (get-buffer-create my-speedbar-buffer-name)
          speedbar-frame (selected-frame)
          dframe-attached-frame (selected-frame)
          speedbar-select-frame-method 'attached
          speedbar-verbosity-level 0
          speedbar-last-selected-file nil)
    (set-buffer speedbar-buffer)
    (speedbar-mode)
    (speedbar-reconfigure-keymaps)
    (speedbar-update-contents)
    (speedbar-set-timer 1)
    (make-local-hook 'kill-buffer-hook)
    (add-hook 'kill-buffer-hook
              (lambda () (when (eq (current-buffer) speedbar-buffer)
                           (setq speedbar-frame nil
                                 dframe-attached-frame nil
                                 speedbar-buffer nil)
                           (speedbar-set-timer nil)))))
  (set-window-buffer (selected-window)
                     (get-buffer my-speedbar-buffer-name)))


(provide 'speedbar-cfg)

;;; speedbar-cfg.el ends here
