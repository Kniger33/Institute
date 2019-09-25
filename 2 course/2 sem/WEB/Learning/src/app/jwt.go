package app

import (
	"../models"
	"../utils"
	"encoding/json"
	"github.com/dgrijalva/jwt-go"
	"net/http"
	"time"
)

var SigningKey = []byte("$c2q3=39*)q5f9415rl5mn!m+j)24@$%_-bd^)e9ic&0p)&5xb")
var Users = map[string]string{
	"Sergei": "123",
}

func LoginHandler(w http.ResponseWriter, r *http.Request) {
	var credentials models.Credentials
	var response models.BaseResponse

	err := json.NewDecoder(r.Body).Decode(&credentials)
	if err != nil {
		response.Error = "Bad request"
		response.Status = false
		w.WriteHeader(http.StatusBadRequest)
		utils.Respond(w, r, response)
		return
	}
	defer r.Body.Close()

	expectedPassword, ok := Users[credentials.Nickname]
	if !ok || expectedPassword != credentials.Password {
		response.Error = "Credentials not found"
		response.Status = false
		w.WriteHeader(http.StatusUnauthorized)
		utils.Respond(w, r, response)
		return
	}

	expirationTime := time.Now().Add(time.Hour * 24)
	claims := &models.Claims{
		Nickname: credentials.Nickname,
		StandardClaims: jwt.StandardClaims{
			ExpiresAt: expirationTime.Unix(),
		},
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	tokenStr, err := token.SignedString(SigningKey)
	if err != nil {
		response.Error = "Some problems"
		response.Status = false
		w.WriteHeader(http.StatusBadRequest)
		utils.Respond(w, r, response)
		return
	}

	response.Status = true
	response.Data = map[string]string{
		"token": tokenStr,
	}
	utils.Respond(w, r, response)
}
