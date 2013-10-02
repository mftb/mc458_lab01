all: Projeto.tex
	pdflatex Projeto
	bibtex Projeto
	pdflatex Projeto
	pdflatex Projeto
	./lint.sh Projeto.tex

clean:
	rm -f Projeto.pdf Projeto.dvi Projeto.ps Projeto.aux Projeto.log Projeto.toc Projeto.bbl Projeto.blg
