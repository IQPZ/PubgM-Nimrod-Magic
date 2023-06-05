
namespace Math
{
	float Distance2D(FVector  v1, FVector v2);
	float Distance3D(FVector  v1, FVector v2);
	D3DXMATRIX Matrix(FRotator rot, FRotator origin = FRotator(0, 0, 0));
	D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2);

}