#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "shaders.hpp"
#include "camera.hpp"

// Screen dimensions
const unsigned int WIDTH = 1280;
const unsigned int HEIGHT = 720;

// Camera
Camera camera(glm::vec3(0.0f, 1.5f, 5.0f));
float lastX = WIDTH / 2.0f;
float lastY = HEIGHT / 2.0f;
bool firstMouse = true;

// Timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// Light source position
glm::vec3 lightPos = glm::vec3(0.0f, 4.5f, 0.0f);

// Function prototypes
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadTexture(const char *path);

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set GLFW options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Art Gallery", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Set callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Capture mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Load textures
    unsigned int floorTexture = loadTexture("../src/assets/floor.jpg");
    printf("floorTexture: %d\n", floorTexture);
    unsigned int ceilingTexture = loadTexture("../src/assets/ceiling.jpg");
    unsigned int wallTexture = loadTexture("../src/assets/wall.jpg");
    unsigned int lightFixtureTexture = loadTexture("../src/assets/light_fixture.jpg");
    unsigned int frameTexture = loadTexture("../src/assets/frame.jpg");
    unsigned int centerpieceTexture = loadTexture("../src/assets/centerpiece.jpg");
    unsigned int pictureTextures[20];
    for (int i = 0; i < 20; ++i)
    {
        std::string path = "../src/assets/pic" + std::to_string(i + 1) + ".jpg";
        pictureTextures[i] = loadTexture(path.c_str());
    }

    // Shader program setup
    Shader shader("../src/shaders/vertex_shader.glsl", "../src/shaders/fragment_shader.glsl");

    // Vertex data for the floor, walls, and ceiling (inside-facing)
    float vertices[] = {
        // Floor
        -5.0f, 0.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // Bottom-left
        5.0f, 0.0f, -5.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // Bottom-right
        5.0f, 0.0f, 5.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,   // Top-right
        -5.0f, 0.0f, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  // Top-left

        // Ceiling
        -5.0f, 5.0f, -5.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, // Bottom-left
        5.0f, 5.0f, -5.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,  // Bottom-right
        5.0f, 5.0f, 5.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,   // Top-right
        -5.0f, 5.0f, 5.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,  // Top-left

        // Back wall
        -5.0f, 0.0f, -5.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
        5.0f, 0.0f, -5.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,  // Bottom-right
        5.0f, 5.0f, -5.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,  // Top-right
        -5.0f, 5.0f, -5.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Top-left

        // Front wall
        -5.0f, 0.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // Bottom-left
        5.0f, 0.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,  // Bottom-right
        5.0f, 5.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,  // Top-right
        -5.0f, 5.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, // Top-left

        // Left wall
        -5.0f, 0.0f, -5.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Bottom-left
        -5.0f, 0.0f, 5.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // Bottom-right
        -5.0f, 5.0f, 5.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // Top-right
        -5.0f, 5.0f, -5.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // Top-left

        // Right wall
        5.0f, 0.0f, -5.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Bottom-left
        5.0f, 0.0f, 5.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // Bottom-right
        5.0f, 5.0f, 5.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // Top-right
        5.0f, 5.0f, -5.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f  // Top-left
    };

    unsigned int indices[] = {
        // Floor
        0, 1, 2,
        2, 3, 0,

        // Ceiling
        4, 5, 6,
        6, 7, 4,

        // Back wall
        8, 9, 10,
        10, 11, 8,

        // Front wall
        12, 13, 14,
        14, 15, 12,

        // Left wall
        16, 17, 18,
        18, 19, 16,

        // Right wall
        20, 21, 22,
        22, 23, 20};

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        // Restrict the camera to the room boundaries
        camera.Position.x = glm::clamp(camera.Position.x, -4.5f, 4.5f);
        camera.Position.y = glm::clamp(camera.Position.y, 0.5f, 4.5f);
        camera.Position.z = glm::clamp(camera.Position.z, -4.5f, 4.5f);

        // Rendering
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Camera and light transformations
        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

        shader.use();
        shader.setVec3("lightPos", lightPos);
        shader.setVec3("viewPos", camera.Position);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        // Draw the floor, ceiling, walls, and objects
        glBindTexture(GL_TEXTURE_2D, floorTexture);
        glm::mat4 model = glm::mat4(1.0f);
        shader.setMat4("model", model);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Ceiling, walls, frames, etc. drawn similarly...

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

unsigned int loadTexture(const char *path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // Flip the image vertically
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cerr << "Failed to load texture: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}