package models

import "net/http"

type BaseResponse struct {
	Error  string      `json:"error"`
	Status bool        `json:"status"`
	Data   interface{} `json:"data"`
}

type loggingResponseWriter struct {
	http.ResponseWriter
	StatusCode int
}

func NewLoggingResponseWriter(w http.ResponseWriter) *loggingResponseWriter {
	return &loggingResponseWriter{w, http.StatusOK}
}

func (lrw *loggingResponseWriter) WriteHeader(code int) {
	lrw.StatusCode = code
	lrw.ResponseWriter.WriteHeader(code)
}
