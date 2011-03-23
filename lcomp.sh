#!/bin/sh

latex presentation.tex
latex presentation.tex
dvips presentation.dvi -o presentation.ps
gv presentation.ps
