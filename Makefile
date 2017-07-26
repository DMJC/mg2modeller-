.PHONY: clean All

All:
	@echo "----------Building project:[ mg2modeller - Debug ]----------"
	@"$(MAKE)" -f  "mg2modeller.mk"
clean:
	@echo "----------Cleaning project:[ mg2modeller - Debug ]----------"
	@"$(MAKE)" -f  "mg2modeller.mk" clean
