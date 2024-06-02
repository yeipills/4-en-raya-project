CXX = g++
CXXFLAGS = -I../../include -I../../src/common -std=c++17 -pthread
LDFLAGS = -lpthread

SRCDIR = ../..
BUILDDIR = ../../build

# Archivos fuente del cliente
CLIENT_SRCS = $(SRCDIR)/src/client/cliente.cpp $(SRCDIR)/src/common/game_logic.cpp

# Objetivo final del cliente
TARGET_CLIENT = $(BUILDDIR)/cliente

# Construye el cliente
all: $(TARGET_CLIENT)

# Regla para construir el cliente
$(TARGET_CLIENT): $(CLIENT_SRCS)
	@mkdir -p $(@D) # Crea el directorio build si no existe
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Limpia los archivos construidos
clean:
	rm -f $(BUILDDIR)/cliente

.PHONY: all clean
