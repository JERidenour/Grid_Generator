clf;

M1 = dlmread('surf_1.txt', '\t');
M2 = dlmread('surf_2.txt', '\t');
M3 = dlmread('surf_3.txt', '\t');

hold on

plot3(M1(:,1), M1(:,2), M1(:,3), 'r*')

plot3(M2(:,1), M2(:,2), M2(:,3), 'b*')

plot3(M3(:,1), M3(:,2), M3(:,3), 'g*')

xlabel('X')
ylabel('Y')
zlabel('Z')
view(3)
