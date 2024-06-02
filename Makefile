CXX = g++
CXXFLAGS = -Iinclude -Isrc/common -std=c++17 -pthread
LDFLAGS = -lpthread

SRCDIR = src
BUILDDIR = build

# Archivos fuente
SERVER_SRCS = $(SRCDIR)/server/servidor.cpp $(SRCDIR)/common/game_logic.cpp
CLIENT_SRCS = $(SRCDIR)/client/cliente.cpp $(SRCDIR)/common/game_logic.cpp

# Objetivos finales
TARGET_SERVER = $(BUILDDIR)/servidor
TARGET_CLIENT = $(BUILDDIR)/cliente

# Construye tanto el servidor como el cliente
all: $(TARGET_SERVER) $(TARGET_CLIENT)

# Regla para construir el servidor
$(TARGET_SERVER): $(SERVER_SRCS)
	@mkdir -p $(@D) # Crea el directorio build si no existe
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regla para construir el cliente
$(TARGET_CLIENT): $(CLIENT_SRCS)
	@mkdir -p $(@D) # Crea el directorio build si no existe
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Limpia los archivos construidos
clean:
	rm -f $(BUILDDIR)/*
	@rmdir $(BUILDDIR) 2>/dev/null || true
