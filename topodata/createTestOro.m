lonlim = [19.5834 20.000];
latlim = [66.7459 67.1625];
[Z refvec] = gtopo30('gtopo30/W020N90', 1, latlim, lonlim); %50 sqm around Harsprånget
%figure
%contourf(A) %see the entire dem tile
Z = Z./1000; %scale data to km above mean sea-level
%figure
%contourf(Z) %show a contour plot of the area
[nx ny] = size(Z);

M = zeros(nx*ny, 3);



col1 = zeros(nx*ny, 1);
k=1;
for i=0:(nx-1)
    for j=1:ny
        
        col1(k) = i;    
        k = k+1;

    end
end

col2 = repmat([0:1:(ny-1)],1,nx)';

col3 = reshape(Z, nx*ny, 1);

M = [col1';col2';col3']';

dlmwrite('OROdat.txt', M, '\t')
