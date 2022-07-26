all: 	main.o Functions.o

# Q0.o Q1.o Q2.o Q3.o Q4.o Q5.o Q6.o Q7.o Q8.o Q9.o Q10.o Q11.o Q12.o Q13.o Q14.o Q15.o Q16.o Q17.o Q18.o Q19.o Q20.o Q21.o Q22.o \
# 			Q23.o Q24.o Q25.o Q26.o Q27.o Q28.o Q29.o Q30.o Q31.o Q32.o Q33.o Q34.o Q35.o Q36.o Q37.o Q38.o Q39.o Q40.o Q41.o Q42.o Q43.o Q44.o Q45.o Q46.o \
# 			Q47.o Q48.o Q49.o Q50.o Q51.o Q52.o Q53.o Q54.o Q55.o Q56.o Q57.o Q58.o Q59.o Q60.o Q61.o Q62.o Q63.o Q64.o Q65.o Q66.o Q67.o Q68.o Q69.o Q70.o \
# 			Q71.o Q72.o Q73.o Q74.o Q75.o Q76.o Q77.o Q78.o Q79.o Q80.o Q81.o Q82.o Q83.o Q84.o Q85.o Q86.o Q87.o Q88.o Q89.o Q90.o Q91.o Q92.o Q93.o Q94.o \
# 			Q95.o Q96.o Q97.o Q98.o Q99.o Q100.o Q101.o Q102.o Q103.o
	g++ -o main main.o Functions.o
	
	
# Q0.o Q1.o Q2.o Q3.o Q4.o Q5.o Q6.o Q7.o Q8.o Q9.o Q10.o Q11.o Q12.o Q13.o Q14.o Q15.o Q16.o Q17.o Q18.o Q19.o Q20.o \
# 		Q21.o Q22.o Q23.o Q24.o Q25.o Q26.o Q27.o Q28.o Q29.o Q30.o Q31.o Q32.o Q33.o Q34.o Q35.o Q36.o Q37.o Q38.o Q39.o Q40.o Q41.o Q42.o Q43.o \
# 		Q44.o Q45.o Q46.o Q47.o Q48.o Q49.o Q50.o Q51.o Q52.o Q53.o Q54.o Q55.o Q56.o Q57.o Q58.o Q59.o Q60.o Q61.o Q62.o Q63.o Q64.o Q65.o Q66.o \
# 		Q67.o Q68.o Q69.o Q70.o Q71.o Q72.o Q73.o Q74.o Q75.o Q76.o Q77.o Q78.o Q79.o Q80.o Q81.o Q82.o Q83.o Q84.o Q85.o Q86.o Q87.o Q88.o Q89.o \
# 		Q90.o Q91.o Q92.o Q93.o Q94.o Q95.o Q96.o Q97.o Q98.o Q99.o Q100.o Q101.o Q102.o Q103.o

	rm -rf *.o

main.o: main.cpp
	g++ -c main.cpp

Functions.o: sources/Functions.cpp
	g++ -c sources/Functions.cpp

# Q0.o: sources/estados/Q0.cpp
# 	g++ -c sources/estados/Q0.cpp

# Q1.o: sources/estados/Q1.cpp
# 	g++ -c sources/estados/Q1.cpp
# Q2.o: sources/estados/Q2.cpp
# 	g++ -c sources/estados/Q2.cpp
# Q3.o: sources/estados/Q3.cpp
# 	g++ -c sources/estados/Q3.cpp
# Q4.o: sources/estados/Q4.cpp
# 	g++ -c sources/estados/Q4.cpp
# Q5.o: sources/estados/Q5.cpp
# 	g++ -c sources/estados/Q5.cpp
# Q6.o: sources/estados/Q6.cpp
# 	g++ -c sources/estados/Q6.cpp
# Q7.o: sources/estados/Q7.cpp
# 	g++ -c sources/estados/Q7.cpp
# Q8.o: sources/estados/Q8.cpp
# 	g++ -c sources/estados/Q8.cpp
# Q9.o: sources/estados/Q9.cpp
# 	g++ -c sources/estados/Q9.cpp
# Q10.o: sources/estados/Q10.cpp
# 	g++ -c sources/estados/Q10.cpp

# Q11.o: sources/estados/Q11.cpp
# 	g++ -c sources/estados/Q11.cpp
# Q12.o: sources/estados/Q12.cpp
# 	g++ -c sources/estados/Q12.cpp
# Q13.o: sources/estados/Q13.cpp
# 	g++ -c sources/estados/Q13.cpp
# Q14.o: sources/estados/Q14.cpp
# 	g++ -c sources/estados/Q14.cpp
# Q15.o: sources/estados/Q15.cpp
# 	g++ -c sources/estados/Q15.cpp
# Q16.o: sources/estados/Q16.cpp
# 	g++ -c sources/estados/Q16.cpp
# Q17.o: sources/estados/Q17.cpp
# 	g++ -c sources/estados/Q17.cpp
# Q18.o: sources/estados/Q18.cpp
# 	g++ -c sources/estados/Q18.cpp
# Q19.o: sources/estados/Q19.cpp
# 	g++ -c sources/estados/Q19.cpp
# Q20.o: sources/estados/Q20.cpp
# 	g++ -c sources/estados/Q20.cpp

# Q21.o: sources/estados/Q21.cpp
# 	g++ -c sources/estados/Q21.cpp
# Q22.o: sources/estados/Q22.cpp
# 	g++ -c sources/estados/Q22.cpp
# Q23.o: sources/estados/Q23.cpp
# 	g++ -c sources/estados/Q23.cpp
# Q24.o: sources/estados/Q24.cpp
# 	g++ -c sources/estados/Q24.cpp
# Q25.o: sources/estados/Q25.cpp
# 	g++ -c sources/estados/Q25.cpp
# Q26.o: sources/estados/Q26.cpp
# 	g++ -c sources/estados/Q26.cpp
# Q27.o: sources/estados/Q27.cpp
# 	g++ -c sources/estados/Q27.cpp
# Q28.o: sources/estados/Q28.cpp
# 	g++ -c sources/estados/Q28.cpp
# Q29.o: sources/estados/Q29.cpp
# 	g++ -c sources/estados/Q29.cpp
# Q30.o: sources/estados/Q30.cpp
# 	g++ -c sources/estados/Q30.cpp

# Q31.o: sources/estados/Q31.cpp
# 	g++ -c sources/estados/Q31.cpp
# Q32.o: sources/estados/Q32.cpp
# 	g++ -c sources/estados/Q32.cpp
# Q33.o: sources/estados/Q33.cpp
# 	g++ -c sources/estados/Q33.cpp
# Q34.o: sources/estados/Q34.cpp
# 	g++ -c sources/estados/Q34.cpp
# Q35.o: sources/estados/Q35.cpp
# 	g++ -c sources/estados/Q35.cpp
# Q36.o: sources/estados/Q36.cpp
# 	g++ -c sources/estados/Q36.cpp
# Q37.o: sources/estados/Q37.cpp
# 	g++ -c sources/estados/Q37.cpp
# Q38.o: sources/estados/Q38.cpp
# 	g++ -c sources/estados/Q38.cpp
# Q39.o: sources/estados/Q39.cpp
# 	g++ -c sources/estados/Q39.cpp
# Q40.o: sources/estados/Q40.cpp
# 	g++ -c sources/estados/Q40.cpp

# Q41.o: sources/estados/Q41.cpp
# 	g++ -c sources/estados/Q41.cpp
# Q42.o: sources/estados/Q42.cpp
# 	g++ -c sources/estados/Q42.cpp
# Q43.o: sources/estados/Q43.cpp
# 	g++ -c sources/estados/Q43.cpp
# Q44.o: sources/estados/Q44.cpp
# 	g++ -c sources/estados/Q44.cpp
# Q45.o: sources/estados/Q45.cpp
# 	g++ -c sources/estados/Q45.cpp
# Q46.o: sources/estados/Q46.cpp
# 	g++ -c sources/estados/Q46.cpp
# Q47.o: sources/estados/Q47.cpp
# 	g++ -c sources/estados/Q47.cpp
# Q48.o: sources/estados/Q48.cpp
# 	g++ -c sources/estados/Q48.cpp
# Q49.o: sources/estados/Q49.cpp
# 	g++ -c sources/estados/Q49.cpp
# Q50.o: sources/estados/Q50.cpp
# 	g++ -c sources/estados/Q50.cpp

# Q51.o: sources/estados/Q51.cpp
# 	g++ -c sources/estados/Q51.cpp
# Q52.o: sources/estados/Q52.cpp
# 	g++ -c sources/estados/Q52.cpp
# Q53.o: sources/estados/Q53.cpp
# 	g++ -c sources/estados/Q53.cpp
# Q54.o: sources/estados/Q54.cpp
# 	g++ -c sources/estados/Q54.cpp
# Q55.o: sources/estados/Q55.cpp
# 	g++ -c sources/estados/Q55.cpp
# Q56.o: sources/estados/Q56.cpp
# 	g++ -c sources/estados/Q56.cpp
# Q57.o: sources/estados/Q57.cpp
# 	g++ -c sources/estados/Q57.cpp
# Q58.o: sources/estados/Q58.cpp
# 	g++ -c sources/estados/Q58.cpp
# Q59.o: sources/estados/Q59.cpp
# 	g++ -c sources/estados/Q59.cpp
# Q60.o: sources/estados/Q60.cpp
# 	g++ -c sources/estados/Q60.cpp

# Q61.o: sources/estados/Q61.cpp
# 	g++ -c sources/estados/Q61.cpp
# Q62.o: sources/estados/Q62.cpp
# 	g++ -c sources/estados/Q62.cpp
# Q63.o: sources/estados/Q63.cpp
# 	g++ -c sources/estados/Q63.cpp
# Q64.o: sources/estados/Q64.cpp
# 	g++ -c sources/estados/Q64.cpp
# Q65.o: sources/estados/Q65.cpp
# 	g++ -c sources/estados/Q65.cpp
# Q66.o: sources/estados/Q66.cpp
# 	g++ -c sources/estados/Q66.cpp
# Q67.o: sources/estados/Q67.cpp
# 	g++ -c sources/estados/Q67.cpp
# Q68.o: sources/estados/Q68.cpp
# 	g++ -c sources/estados/Q68.cpp
# Q69.o: sources/estados/Q69.cpp
# 	g++ -c sources/estados/Q69.cpp
# Q70.o: sources/estados/Q70.cpp
# 	g++ -c sources/estados/Q70.cpp

# Q71.o: sources/estados/Q71.cpp
# 	g++ -c sources/estados/Q71.cpp
# Q72.o: sources/estados/Q72.cpp
# 	g++ -c sources/estados/Q72.cpp
# Q73.o: sources/estados/Q73.cpp
# 	g++ -c sources/estados/Q73.cpp
# Q74.o: sources/estados/Q74.cpp
# 	g++ -c sources/estados/Q74.cpp
# Q75.o: sources/estados/Q75.cpp
# 	g++ -c sources/estados/Q75.cpp
# Q76.o: sources/estados/Q76.cpp
# 	g++ -c sources/estados/Q76.cpp
# Q77.o: sources/estados/Q77.cpp
# 	g++ -c sources/estados/Q77.cpp
# Q78.o: sources/estados/Q78.cpp
# 	g++ -c sources/estados/Q78.cpp
# Q79.o: sources/estados/Q79.cpp
# 	g++ -c sources/estados/Q79.cpp
# Q80.o: sources/estados/Q80.cpp
# 	g++ -c sources/estados/Q80.cpp

# Q81.o: sources/estados/Q81.cpp
# 	g++ -c sources/estados/Q81.cpp
# Q82.o: sources/estados/Q82.cpp
# 	g++ -c sources/estados/Q82.cpp
# Q83.o: sources/estados/Q83.cpp
# 	g++ -c sources/estados/Q83.cpp
# Q84.o: sources/estados/Q84.cpp
# 	g++ -c sources/estados/Q84.cpp
# Q85.o: sources/estados/Q85.cpp
# 	g++ -c sources/estados/Q85.cpp
# Q86.o: sources/estados/Q86.cpp
# 	g++ -c sources/estados/Q86.cpp
# Q87.o: sources/estados/Q87.cpp
# 	g++ -c sources/estados/Q87.cpp
# Q88.o: sources/estados/Q88.cpp
# 	g++ -c sources/estados/Q88.cpp
# Q89.o: sources/estados/Q89.cpp
# 	g++ -c sources/estados/Q89.cpp
# Q90.o: sources/estados/Q90.cpp
# 	g++ -c sources/estados/Q90.cpp

# Q91.o: sources/estados/Q91.cpp
# 	g++ -c sources/estados/Q91.cpp
# Q92.o: sources/estados/Q92.cpp
# 	g++ -c sources/estados/Q92.cpp
# Q93.o: sources/estados/Q93.cpp
# 	g++ -c sources/estados/Q93.cpp
# Q94.o: sources/estados/Q94.cpp
# 	g++ -c sources/estados/Q94.cpp
# Q95.o: sources/estados/Q95.cpp
# 	g++ -c sources/estados/Q95.cpp
# Q96.o: sources/estados/Q96.cpp
# 	g++ -c sources/estados/Q96.cpp
# Q97.o: sources/estados/Q97.cpp
# 	g++ -c sources/estados/Q97.cpp
# Q98.o: sources/estados/Q98.cpp
# 	g++ -c sources/estados/Q98.cpp
# Q99.o: sources/estados/Q99.cpp
# 	g++ -c sources/estados/Q99.cpp
# Q100.o: sources/estados/Q100.cpp
# 	g++ -c sources/estados/Q100.cpp

# Q101.o: sources/estados/Q101.cpp
# 	g++ -c sources/estados/Q101.cpp
# Q102.o: sources/estados/Q102.cpp
# 	g++ -c sources/estados/Q102.cpp
# Q103.o: sources/estados/Q103.cpp
# 	g++ -c sources/estados/Q103.cpp

run:
	./main -p files/testes/fat.txt files/saidas/saida.txt