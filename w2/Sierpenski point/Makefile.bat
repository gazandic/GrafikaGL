set CXX=g++
set GL=-lglut32cu -lglu32 -lopengl32
set GLEW=-DUSEGLEW -lglew32
set CFLAGS=-Wall -Wextra %GL%
set DEBUG=
set SOURCE=

for /f "delims=" %%i in ('dir /b src') do set SOURCE=%%i

%CXX% -o bin/main.exe src/%SOURCE% %CFLAGS% %DEBUG%