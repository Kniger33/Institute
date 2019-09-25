package middleware

import (
	"../models"
	"log"
	"net/http"
)

func LoggingMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		lrw := models.NewLoggingResponseWriter(w)
		next.ServeHTTP(lrw, r)
		log.Printf("%6v %15v %3v", r.Method, r.URL, lrw.StatusCode)
	})
}
