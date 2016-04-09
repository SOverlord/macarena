all: servidor cliente

servidor:
	gcc -w -o server server.c

cliente:
	gcc -w -o client client.c

clean:
	rm -rf server client

clt:
	./client 10.50.178.155 9004

git:
	$ git add .
	$ git add -A
	$ git commit -m "last"
	$ git push origin master