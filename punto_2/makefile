cuerda.gif: datos.txt
	python animacion.py
	rm datos.txt

datos.txt:
	c++ cuerda.cpp -o rs.rs
	./rs.rs > datos.txt
	rm rs.rs
