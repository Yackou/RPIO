all: pwm py2.6 py2.7 py3.2 py3.3 py3.4 py3.5 py3.6

pwm:
	gcc -Wall -g -O2 -o pwm pwm.c

py2.6:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.6 -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.6 -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.6 -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.6 -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build

py2.7:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.7 -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.7 -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.7 -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.7 -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build

py3.2:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.2mu -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.2mu -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.2mu -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.2mu -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build

py3.3:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.3mu -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.3mu -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.3mu -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.3mu -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build
	
py3.4:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.4mu -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.4mu -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.4mu -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.4mu -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build
	
py3.5:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.5mu -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.5mu -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.5mu -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.5mu -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build
	
py3.6:
	mkdir -p build
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.6mu -c mailbox.c -o build/mailbox.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.6mu -c pwm.c -o build/pwm.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.6mu -c pwm_py.c -o build/pwm_py.o
	gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python3.6mu -c cpuinfo.c -o build/cpuinfo.o
	gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-z,relro build/mailbox.o build/cpuinfo.o build/pwm.o build/pwm_py.o -o _PWM.so
	rm -rf build