using System;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(MazeConstructor))]

public class GameController : MonoBehaviour
{
    //1. Сначала вы внедрили сериализованные поля для каждого объекта в сцене.
    [SerializeField] private FpsMovement player;
    [SerializeField] private Text timeLabel;
    [SerializeField] private Text scoreLabel;

    private MazeConstructor generator;

    // 2. Несколько личных переменных были добавлены, чтобы отследить таймер игры, счет, и узнать была ли найдена цель лабиринта
    private DateTime startTime;
    private int timeLimit;
    private int reduceLimitBy;

    private int score;
    private bool goalReached;

    // 3. MazeConstructorактивируется так же, как и раньше, но сейчас параметр Start() 
    //использует новые методы, которые делают больше, чем просто вызов GenerateNewMaze().
    void Start()
    {
        generator = GetComponent<MazeConstructor>();
        StartNewGame();
    }

    // 4. StartNewGame()используется для запуска всей игры с самого начала, 
    // в отличие от переключения между уровнями в игре. Таймер устанавливается
    // на начальные значения, счет сбрасывается, а затем создается лабиринт
    private void StartNewGame()
    {
        timeLimit = 80;
        reduceLimitBy = 5;
        startTime = DateTime.Now;

        score = 0;
        scoreLabel.text = score.ToString();

        StartNewMaze();
    }

    // 5.	StartNewMaze()отвечает за переход на следующий уровень без начала всей игры.
    // Кроме создания нового лабиринта, этот метод отправит игрока в начало уровня, сбросит цель и сократит время.
    private void StartNewMaze()
    {
        generator.GenerateNewMaze(13, 15, OnStartTrigger, OnGoalTrigger);

        float x = generator.StartCol * generator.HallWidth;
        float y = 1;
        float z = generator.StartRow * generator.HallWidth;
        player.transform.position = new Vector3(x, y, z);

        goalReached = false;
        player.enabled = true;

        // restart timer
        timeLimit -= reduceLimitBy;
        startTime = DateTime.Now;
    }

    // 6. Update()смотрит за активностью игрока, после чего обновляет оставшееся минуты до завершения уровня.
    // Когда время истекло, игрока выкинет и запустится новая игра
    void Update()
    {
        if (!player.enabled)
        {
            return;
        }

        int timeUsed = (int)(DateTime.Now - startTime).TotalSeconds;
        int timeLeft = timeLimit - timeUsed;

        if (timeLeft > 0)
        {
            timeLabel.text = timeLeft.ToString();
        }
        else
        {
            timeLabel.text = "TIME UP";
            player.enabled = false;

            Invoke("StartNewGame", 4);
        }
    }

    //7 Этот триггер проверяет, что цель была найдена, а затем увеличивает счет.
    private void OnGoalTrigger(GameObject trigger, GameObject other)
    {
        Debug.Log("Goal!");
        goalReached = true;

        score += 1;
        scoreLabel.text = score.ToString();

        Destroy(trigger);
    }

    // Проверяет, была ли цель достигнута, а затем выбрасывает игрока и запускает новый лабиринт
    private void OnStartTrigger(GameObject trigger, GameObject other)
    {
        if (goalReached)
        {
            Debug.Log("Finish!");
            player.enabled = false;

            Invoke("StartNewMaze", 4);
        }
    }
}
