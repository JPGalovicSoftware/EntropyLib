#include <GL/glew.h>

#include <GLApplication.h>
#include <GLWindow.h>
#include <GLShader.h>

#include <Vector4.h>
#include <Clock.h>

#include <thread>
#include <iostream>

using namespace Entropy::Math;
using namespace Entropy::Timing;

void sleep(unsigned int millis);

int main(int argc, char** argv)
{
	Clock myClock;

	// Initalize Applicaiton & Window
	Entropy::GLApplication myApplication;
	myApplication.initializeGLFW();
	Entropy::GLWindow myWindow(800, 600, "LearnOpenGL");
	myApplication.initializeGLEW();

	myWindow.setWindowClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate Shader Program
	Entropy::GLShader shader("E:/Onedrive/Scratch/CPPScratch/EntropyLib/x64/Debug/vShader.glsl", "E:/Onedrive/Scratch/CPPScratch/EntropyLib/x64/Debug/fShader.glsl");
	
	// Initialize Triangle
	Vector4 verts[] =
	{
	/**
	 *	posistions			//colors
	 *	x    , y    , z    ,	r    , g    , b    , a    ,
	 */
		Vector4( 0.0f,  0.1f), Vector4(1.0f,  1.0f,  0.0f,  1.0f),
		Vector4(-0.1f, -0.1f), Vector4(0.0f,  1.0f,  1.0f,  1.0f),
		Vector4( 0.1f, -0.1f), Vector4(1.0f,  0.0f,  1.0f,  1.0f)
	};
	
	unsigned int indices[] =
	{
		0, 1, 2,
	};

	// Initalize Vertex Buffer and Array
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	// Bind buffer and copy in our vertex data
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Define how OpenGL shoudl interperate the vertex data
	// Vertex Position
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Vertex Color
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Enter Wireframe Mode

	Vector4 offset(-0.5f, -0.5f);
	Vector4 velosity(0.3f, 0.3f); // px/s

	// Init Clock
	myClock.initialize();

	unsigned int lagGen = 0;

	// Gameloop
	while (!myWindow.getShouldClose())
	{
		// Input
		if (myWindow.getKeyPressed(Entropy::GLKeys::KEY_ESCAPE))
			myWindow.setShouldClose(true);

		// Render
		myWindow.render();

		const unsigned int numVerts = sizeof(verts) / sizeof(*verts);

		Vector4 translatedVerts[numVerts];
		for (unsigned int i = 1; i < numVerts; i = i + 2)
		{
			translatedVerts[i - 1] = verts[i - 1] + offset;
			translatedVerts[i] = verts[i];
		}

		// Use our shader program
		shader.use();
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

		// Update
		myWindow.processEvents();
		offset = offset + (velosity * myClock.timeElapsed());

		myClock.poll();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	myClock.shutdown();

	return 0;
}

void sleep(unsigned int millis)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}