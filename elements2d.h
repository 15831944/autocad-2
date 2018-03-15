#include <string>
#include <vector>
using namespace std;

class Vertex2d
{
	public:
	Vertex3d proj_of;
	double x, y, z;
	double length;
	vector<char> name;

	Vertex2d(int first, int second, int third, string name_c)
	{
		x = first;
		y = second;
		z = third;
		
		for (int i = 0; i < name_c.length(); ++i)
		{
			name.push_back(name_c.at(i));
		}
	}
	Vertex2d()
	{
		
	}
	void translate(vector<double> direction, double units)
	{
		cout << "direction vector: " << endl;
		for (int i=0; i<direction.size(); i++)
       		cout << direction[i] << " ";

       	double u = direction[0]*direction[0] + direction[1]*direction[1];
       	double u_x = direction[0] / sqrt(u);
       	double u_y = direction[1] / sqrt(u);
       	
       	MatrixXd T(2,1);
	    T(0,0) = units*u_x;
	    T(1,0) = units*u_y;
	    
       	MatrixXd p(2,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = T + p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	    
	}
	void mirror(int plane)
	{

	}
	void rotate(int direction, int degrees)
	{

	}
	void scale(float factor)
	{

	}
};

class Edge2d
{
	public:
	Vertex2d v1, v2;
	Edge3d proj_of;
	bool hidden;
	// data of which plane?
	Edge2d (Vertex2d v1_c, Vertex2d v2_c)
	{
		v1 = v1_c;
		v2 = v2_c;
		hidden = false;
	}
	Edge2d()
	{

	}
	void translate(int direction, float value)
	{
		//direction 1->x 2->y 3->z
	}
	void mirror(int plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
	}
	void rotate(int direction, int degrees)
	{
		//direction protocol same as translate, degrees always clockwise
	}
	void scale(float factor)
	{
		//scales by input factor
	}
};

class Surface2d
{
public:
	int num_edges;
	vector<Edge2d> edges;
	Surface2d(vector<Edge2d> edges_c, int num_edges_c)
	{	
		edges = edges_c;
		num_edges = num_edges_c;
	}
	//Add functionalities.
};

class object2d
{
	public:
	vector<Vertex2d> vertices;
	vector<Edge2d> edges;
	vector<Surface2d> surfaces;
};