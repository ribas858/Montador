all: 	ligador_rb.o Functions.o

# Q0.o Q1.o Q2.o Q3.o Q4.o Q5.o Q6.o Q7.o Q8.o Q9.o Q10.o Q11.o Q12.o Q13.o Q14.o Q15.o Q16.o Q17.o Q18.o Q19.o Q20.o Q21.o Q22.o \
# 			Q23.o Q24.o Q25.o Q26.o Q27.o Q28.o Q29.o Q30.o Q31.o Q32.o Q33.o Q34.o Q35.o Q36.o Q37.o Q38.o Q39.o Q40.o Q41.o Q42.o Q43.o Q44.o Q45.o Q46.o \
# 			Q47.o Q48.o Q49.o Q50.o Q51.o Q52.o Q53.o Q54.o Q55.o Q56.o Q57.o Q58.o Q59.o Q60.o Q61.o Q62.o Q63.o Q64.o Q65.o Q66.o Q67.o Q68.o Q69.o Q70.o \
# 			Q71.o Q72.o Q73.o Q74.o Q75.o Q76.o Q77.o Q78.o Q79.o Q80.o Q81.o Q82.o Q83.o Q84.o Q85.o Q86.o Q87.o Q88.o Q89.o Q90.o Q91.o Q92.o Q93.o Q94.o \
# 			Q95.o Q96.o Q97.o Q98.o Q99.o Q100.o Q101.o Q102.o Q103.o
	g++ -o ligador_rb ligador_rb.o Functions.o
	
	
# Q0.o Q1.o Q2.o Q3.o Q4.o Q5.o Q6.o Q7.o Q8.o Q9.o Q10.o Q11.o Q12.o Q13.o Q14.o Q15.o Q16.o Q17.o Q18.o Q19.o Q20.o \
# 		Q21.o Q22.o Q23.o Q24.o Q25.o Q26.o Q27.o Q28.o Q29.o Q30.o Q31.o Q32.o Q33.o Q34.o Q35.o Q36.o Q37.o Q38.o Q39.o Q40.o Q41.o Q42.o Q43.o \
# 		Q44.o Q45.o Q46.o Q47.o Q48.o Q49.o Q50.o Q51.o Q52.o Q53.o Q54.o Q55.o Q56.o Q57.o Q58.o Q59.o Q60.o Q61.o Q62.o Q63.o Q64.o Q65.o Q66.o \
# 		Q67.o Q68.o Q69.o Q70.o Q71.o Q72.o Q73.o Q74.o Q75.o Q76.o Q77.o Q78.o Q79.o Q80.o Q81.o Q82.o Q83.o Q84.o Q85.o Q86.o Q87.o Q88.o Q89.o \
# 		Q90.o Q91.o Q92.o Q93.o Q94.o Q95.o Q96.o Q97.o Q98.o Q99.o Q100.o Q101.o Q102.o Q103.o

	rm -rf *.o

ligador_rb.o: ligador_rb.cpp
	g++ -c ligador_rb.cpp

Functions.o: sources/Functions.cpp
	g++ -c sources/Functions.cpp


run:
	./ligador_rb files/saidas/saida_meu_fat_a.txt files/saidas/saida_meu_fat_b.txt