all: servidor cliente

servidor:
	gcc -w -o srv server.c

cliente:
	gcc -w -o clt client.c

clean:
	rm -rf srv clt

git:
	$ git add .
	$ git add -A
	$ git commit -m "last"
	$ git push origin master