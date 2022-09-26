OBJS = main.o
C = g++
O = -o
PT = -lpthread
RM = rm *.o
DR = donor_registration.o
RR = receiver_registration.o
RRO = receiver_related_operations.o
MDD = manage_donor_data.o
RP = report.o
EV = employee_validation.o
DFO = donor_file_operation.o
RFO = transaction_file_operation.o
SUBO = submenu.o
VALO = Validation.o

MCPP = main.cpp
SUBCPP = submenu.cpp
DRCPP = donor_registration.cpp
RRCPP = receiver_registration.cpp
RROCPP = receiver_related_operations.cpp
MDDCPP = manage_donor_data.cpp
RPCPP = report.cpp
EVCPP = employee_validation.cpp
DFOCPP = donor_file_operation.cpp
RFOCPP = transaction_file_operation.cpp
VALCPP = Validation.cpp


test : $(OBJS)
	$(C) -o $(OBJS) $(SUBO) $(DR) $(RR) $(RRO) $(MDD) $(RP) $(EV) $(DFO) $(RFO) $(VALCPP)

main.o : main.cpp
	$(C) -c  $(MCPP)

$(DR) : $(DRCPP)
	$(C) -c $(DRCPP)

$(RR): $(RRCPP)
	$(C) -c $(RRCPP)

$(RRO) : $(RROCPP)
	$(C) -c $(RROCPP)

$(MDD): $(MDDCPP)
	$(C) -c $(MDDCPP)

$(RP): $(RPCPP)
	 $(C) $(RPCPP)

$(EV) : $(EVCPP)
	$(C) -c $(EVCPP)

$(DFO) : $(DFOCPP)
	$(C) -c $(DFOCPP)

$(RFO) : $(RFOCPP)
	$(C) -c $(RFOCPP)

$(VALCPP) : $(VALCPP)
	$(C) -c $(VALCPP)

clean : 
	$(RM)

