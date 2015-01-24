class interrupt {
	static interrupt *owner[35];
	virtual void serviceRoutine() = 0;
	static void handler1() __asm__("__vector_1") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler2() __asm__("__vector_2") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler3() __asm__("__vector_3") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler4() __asm__("__vector_4") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler5() __asm__("__vector_5") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler6() __asm__("__vector_6") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler7() __asm__("__vector_7") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler8() __asm__("__vector_8") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler9() __asm__("__vector_9") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler10() __asm__("__vector_10") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler11() __asm__("__vector_11") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler12() __asm__("__vector_12") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler13() __asm__("__vector_13") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler14() __asm__("__vector_14") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler15() __asm__("__vector_15") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler16() __asm__("__vector_16") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler17() __asm__("__vector_17") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler18() __asm__("__vector_18") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler19() __asm__("__vector_19") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler20() __asm__("__vector_20") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler21() __asm__("__vector_21") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler22() __asm__("__vector_22") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler23() __asm__("__vector_23") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler24() __asm__("__vector_24") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler25() __asm__("__vector_25") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler26() __asm__("__vector_26") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler27() __asm__("__vector_27") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler28() __asm__("__vector_28") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler29() __asm__("__vector_29") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler30() __asm__("__vector_30") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler31() __asm__("__vector_31") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler32() __asm__("__vector_32") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler33() __asm__("__vector_33") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler34() __asm__("__vector_34") __attribute__((__signal__, __used__, __externally_visible__));
	static void handler35() __asm__("__vector_35") __attribute__((__signal__, __used__, __externally_visible__));


public:
	static void record(int interruptNumber, interrupt *i);
};