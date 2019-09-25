package main

import (
	"./app"
	"./middleware"
	"github.com/gorilla/mux"
	"log"
	"net/http"
	"time"
)

func main() {
	Router := mux.NewRouter()

	unauthRouter := Router.PathPrefix("/").Subrouter()
	unauthRouter.HandleFunc("/", app.HomeHandler).Methods("GET")
	unauthRouter.HandleFunc("/login", app.LoginHandler).Methods("POST")

	authRouter := Router.PathPrefix("/auth").Subrouter()
	authRouter.Use(middleware.AuthMiddleware)
	authRouter.HandleFunc("/info", app.InfoHandler).Methods("GET")

	Router.Use(middleware.LoggingMiddleware)

	server := http.Server{
		Handler:      Router,
		Addr:         ":8080",
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}

	log.Printf("Server started work at %v", server.Addr)
	log.Fatal(server.ListenAndServe())
}
