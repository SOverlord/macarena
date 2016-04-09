all: servidor cliente

servidor:
	gcc -w -o server server.c

cliente:
	gcc -w -o client client.c

clean:
	rm -rf server client

git:
	$ git add .
	$ git add -A
	$ git commit -m "last"
	$ git push origin master