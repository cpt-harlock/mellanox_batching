TARGET = ioctl
OBJS = $(patsubst %,%.o,$(TARGET))

CFLAGS = -Wno-multichar

# Add colors to the output
# https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

#BOLD = \033[1m

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "${GREEN}Linking...${NC}"
	gcc $^ -o $@
	@echo "${GREEN}Done!${NC}"

$(OBJS): %.o: %.c
	@echo "${GREEN}Compiling $<...${NC}"
	gcc $(CFLAGS) -c $^ -o $@
	@echo "${GREEN}Done!${NC}"
clean:
	@echo "${RED}Cleaning...${NC}"
	rm $(TARGET) $(OBJS)
	@echo "${RED}Done!${NC}"
