main: main.c
	gcc -o dla main.c list.c point.c

clean:
	rm dla