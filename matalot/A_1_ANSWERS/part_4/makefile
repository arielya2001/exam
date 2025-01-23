CC = gcc
CFLAGS = -Wall 

LIB = libadvmath.so
OBJS = advmath.o
MAIN = main.o
 

all: progDync progDync2

# יש שני שיטות, שאנחנו ממליצים לעשות לינק בזמן ריצה לספריה הדינמית
#שיטה 1

# על מנת שהלינקר הדינמי של לינוקד ידע לחבר את הספרייה בזמן ריצה, יש להרי. את הפקודה
# ולאחר מכן להריץ את הפקודה הבאה
#export LD_LIBRARY_PATH=.
progDync: $(MAIN) $(LIB)
	$(CC) -o $@ $(MAIN) -L. -ladvmath ./$(LIB)
	export LD_LIBRARY_PATH=.

#שיטה 2
#הדגל בסוף הפקודה
# Wl,-rpath,.
# Wl- דגל זה אומר למהדר להעביר את האופציה הבאה ישירות ללינקר
# rpath,. זוהי ההוראה עצמה ללינקר, שקובעת נתיב חיפוש קבוע לספריות דינמיות
# ליותר מידע אני ממליץ לקרוא על הדגל 
# man gcc -ולחפש את הדגל כאן
progDync2: $(MAIN) $(LIB)
	$(CC) -o $@ $(MAIN) -L. -ladvmath -Wl,-rpath,.

#קימפול ויצירת ספריה דינמית
advmath.o: advmath.c advmath.h
	$(CC) $(CFLAGS) -c -fPIC $< -o $@

$(LIB): $(OBJS)
	$(CC) -shared $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f *.o *.so progDync progDync2

.PHONY: all clean