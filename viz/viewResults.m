M = dlmread('testOutput.txt', '\t');
plot3(M(:,1), M(:,2), M(:,3), '*')