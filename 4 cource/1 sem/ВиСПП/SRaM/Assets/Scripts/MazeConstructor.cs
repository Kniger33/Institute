using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MazeConstructor : MonoBehaviour
{
    //1 showDebug будет использоваться для отображения окна отладки
    [SerializeField] private bool showDebug;

    [SerializeField] private Material materialFloor;//mazeMat1;
    [SerializeField] private Material materiaWall;//mazeMat2;
    [SerializeField] private Material startMat;
    [SerializeField] private Material treasureMat;

    private MazeDataGenerator dataGenerator;
    private MazeMeshGenerator meshGenerator;

    //2 свойство данных лабиринта 
    public int[,] Data { get; private set; }
    public float HallWidth { get; private set; }
    public float HallHeight { get; private set; }
    public int StartRow { get; private set; }
    public int StartCol { get; private set; }
    public int GoalRow { get; private set; }
    public int GoalCol { get; private set; }

    #region UnityEvents
    //3
    void Awake()
    {
        dataGenerator = new MazeDataGenerator();
        meshGenerator = new MazeMeshGenerator();
        // default to walls surrounding a single empty cell
        Data = new int[,]
        {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        };
    }

    void OnGUI()
    {
        //1 включены ли отладочные дисплеи.
        if (!showDebug)
        {
            return;
        }

        //2. Вы сможете инициализировать несколько событий локальных переменных: копию готового лабиринта, 
        // максимальную строку, столбец а также строку для построения
        int[,] maze = Data;
        int rMax = maze.GetUpperBound(0);
        int cMax = maze.GetUpperBound(1);

        string msg = "";

        for (int i = rMax; i >= 0; i--)
        {
            for (int j = 0; j <= cMax; j++)
            {
                if (maze[i, j] == 0)
                {
                    msg += "....";
                }
                else
                {
                    msg += "==";
                }
            }
            msg += "\n";
        }

        GUI .Label(new Rect(20, 20, 500, 500), msg);
    }

    #endregion

    public void GenerateNewMaze(int sizeRows, int sizeCols,
    TriggerEventHandler startCallback = null, TriggerEventHandler goalCallback = null)
    {
        if (sizeRows % 2 == 0 && sizeCols % 2 == 0)
        {
            Debug.LogError("Odd numbers work better for dungeon size.");
        }

        DisposeOldMaze();

        Data = dataGenerator.FromDimensions(sizeRows, sizeCols);

        FindStartPosition();
        FindGoalPosition();

        // store values used to generate this mesh
        HallWidth = meshGenerator.Width;
        HallHeight = meshGenerator.Height;

        DisplayMaze();

        PlaceStartTrigger(startCallback);
        PlaceGoalTrigger(goalCallback);
    }


    public void DisplayMaze()
    {
        GameObject go = new GameObject();
        go.transform.position = Vector3.zero;
        go.name = "Procedural Maze";
        go.tag = "Generated";

        MeshFilter meshFilter = go.AddComponent<MeshFilter>();
        meshFilter.mesh = meshGenerator.FromData(Data);

        MeshCollider meshCollider = go.AddComponent<MeshCollider>();
        meshCollider.sharedMesh = meshFilter.mesh;

        MeshRenderer meshRenderer = go.AddComponent<MeshRenderer>();
        meshRenderer.materials = new Material[2] {materialFloor, materiaWall};

    }

    public void DisposeOldMaze()
    {
        GameObject[] objects = GameObject.FindGameObjectsWithTag("Generated");
        foreach (GameObject go in objects)
        {
            Destroy(go);
        }
    }

    private void FindStartPosition()
    {
        int[,] maze = Data;
        int rMax = maze.GetUpperBound(0);
        int cMax = maze.GetUpperBound(1);

        for (int i = 0; i <= rMax; i++)
        {
            for (int j = 0; j <= cMax; j++)
            {
                if (maze[i, j] == 0)
                {
                    StartRow = i;
                    StartCol = j;
                    return;
                }
            }
        }
    }

    private void FindGoalPosition()
    {
        int[,] maze = Data;
        int rMax = maze.GetUpperBound(0);
        int cMax = maze.GetUpperBound(1);

        // loop top to bottom, right to left
        for (int i = rMax; i >= 0; i--)
        {
            for (int j = cMax; j >= 0; j--)
            {
                if (maze[i, j] == 0)
                {
                    GoalRow = i;
                    GoalCol = j;
                    return;
                }
            }
        }
    }

    private void PlaceStartTrigger(TriggerEventHandler callback)
    {
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
        go.transform.position = new Vector3(StartCol * HallWidth, .5f, StartRow * HallWidth);
        go.name = "Start Trigger";
        go.tag = "Generated";

        go.GetComponent<BoxCollider>().isTrigger = true;
        go.GetComponent<MeshRenderer>().sharedMaterial = startMat;

        TriggerEventRouter tc = go.AddComponent<TriggerEventRouter>();
        tc.callback = callback;
    }

    private void PlaceGoalTrigger(TriggerEventHandler callback)
    {
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
        go.transform.position = new Vector3(GoalCol * HallWidth, .5f, GoalRow * HallWidth);
        go.name = "Treasure";
        go.tag = "Generated";

        go.GetComponent<BoxCollider>().isTrigger = true;
        go.GetComponent<MeshRenderer>().sharedMaterial = treasureMat;

        TriggerEventRouter tc = go.AddComponent<TriggerEventRouter>();
        tc.callback = callback;
    }


}

