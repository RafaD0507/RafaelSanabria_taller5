placas.pdf: datos.txt
	python grafica.py
	rm datos.txt

datos.txt:
	c++ placas.cpp -o rs.rs
	./rs.rs > datos.txt
	rm rs.rs
