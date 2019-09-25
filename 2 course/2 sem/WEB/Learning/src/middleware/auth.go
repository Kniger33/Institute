package middleware

import (
	"../app"
	"../models"
	"../utils"
	"context"
	"github.com/dgrijalva/jwt-go"
	"net/http"
)

func AuthMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		var response models.BaseResponse

		tokenStr := r.Header.Get("Authorization")
		if tokenStr == "" {
			response.Error = "Unauthorized"
			response.Status = false
			w.WriteHeader(http.StatusUnauthorized)
			utils.Respond(w, r, response)
			return
		}

		claims := &models.Claims{}

		token, err := jwt.ParseWithClaims(tokenStr, claims, func(token *jwt.Token) (i interface{}, e error) {
			return app.SigningKey, nil
		})
		if !token.Valid {
			response.Error = "Unauthorized"
			response.Status = false
			w.WriteHeader(http.StatusUnauthorized)
			utils.Respond(w, r, response)
			return
		}
		if err != nil {
			if err == jwt.ErrSignatureInvalid {
				response.Error = "Unauthorized"
				response.Status = false
				w.WriteHeader(http.StatusUnauthorized)
				utils.Respond(w, r, response)
				return
			}
			response.Error = "Bad request"
			response.Status = false
			w.WriteHeader(http.StatusBadRequest)
			utils.Respond(w, r, response)
			return
		}

		ctx := context.WithValue(r.Context(), "user", claims)
		next.ServeHTTP(w, r.WithContext(ctx))
	})
}
