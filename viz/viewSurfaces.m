clf;

M1 = dlmread('surf_1.txt', '\t');
M2 = dlmread('surf_2.txt', '\t');
M3 = dlmread('surf_3.txt', '\t');
M4 = dlmread('surf_4.txt', '\t');
M5 = dlmread('surf_5.txt', '\t');
M6 = dlmread('surf_6.txt', '\t');

L1 = dlmread('north_linetest.txt', '\t');
L2 = dlmread('south_linetest.txt', '\t');
L3 = dlmread('east_linetest.txt', '\t');
L4 = dlmread('west_linetest.txt', '\t');

MT = dlmread('testtop.txt', '\t');
MTb = dlmread('testbottom.txt', '\t');

hold on

%plot3(M1(:,1), M1(:,2), M1(:,3), 'r*')
%plot3(M2(:,1), M2(:,2), M2(:,3), 'b*')
%plot3(M3(:,1), M3(:,2), M3(:,3), 'g*')
%plot3(M4(:,1), M4(:,2), M4(:,3), 'k*')
%plot3(M5(:,1), M5(:,2), M5(:,3), 'm*')
%plot3(M6(:,1), M6(:,2), M6(:,3), 'c*')

plot3(MT(:,1), MT(:,2), MT(:,3), 'm*')
plot3(MTb(:,1), MTb(:,2), MTb(:,3), 'c*')

plot3(L1(:,1), L1(:,2), L1(:,3), 'r*')
plot3(L2(:,1), L2(:,2), L2(:,3), 'b*')
plot3(L3(:,1), L3(:,2), L3(:,3), 'g*')
plot3(L4(:,1), L4(:,2), L4(:,3), 'k*')

xlabel('X')
ylabel('Y')
zlabel('Z')
view(3)
