TARGET = ioctl
OBJS = $(patsubst %,%.o,$(TARGET))

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc $^ -o $@

$(OBJS): %.o: %.c
	gcc -c $^ -o $@
clean:
	rm $(TARGET) $(OBJS)
