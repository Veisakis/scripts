# -*- MakeFile -*-

new_article: htmlStrip article
	./htmlStrip < html_sample | ./new_article	

rss: updateRSS
	./updateRSS < article

install: htmlStrip.o new_article.o updateRSS.o
	gcc htmlStrip.o -o htmlStrip
	gcc new_article.o -o article
	gcc updateRSS.o -o updateRSS

updateRSS.o: updateRSS.c
	gcc -c updateRSS.c

new_article.o: article.c
	gcc -c new_article.c

htmlStrip.o: htmlStrip.c
	gcc -c htmlStrip.c

clean:
	rm -f *.o htmlStrip new_article updateRSS
	head -n5 header > article
	head -n-2 rss_final > rss_blank

