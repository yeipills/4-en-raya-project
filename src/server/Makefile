CXX = g++
CXXFLAGS = -I../../include -I../../src/common -std=c++17 -pthread
LDFLAGS = -lpthread

SRCDIR = ../..
BUILDDIR = ../../build

# Archivos fuente del servidor
SERVER_SRCS = $(SRCDIR)/src/server/servidor.cpp $(SRCDIR)/src/common/game_logic.cpp

# Objetivo final del servidor
TARGET_SERVER = $(BUILDDIR)/servidor

# Construye el servidor
all: $(TARGET_SERVER)

# Regla para construir el servidor
$(TARGET_SERVER): $(SERVER_SRCS)
	@mkdir -p $(@D) # Crea el directorio build si no existe
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Limpia los archivos construidos
clean:
	rm -f $(BUILDDIR)/servidor

.PHONY: all clean
