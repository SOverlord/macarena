all: servidor cliente

servidor:
	gcc -o srv server.c

cliente:
	gcc -o clt client.c

clean:
	rm -rf srv clt

git:
	$ git add .
	$ git add -A
	$ git commit -m "last"
	$ git push origin master