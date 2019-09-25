package models

import "github.com/dgrijalva/jwt-go"

type Claims struct {
	jwt.StandardClaims
	Nickname string `json:"nickname"`
}

type Credentials struct {
	Nickname string `json:"nickname"`
	Password string `json:"password"`
}
