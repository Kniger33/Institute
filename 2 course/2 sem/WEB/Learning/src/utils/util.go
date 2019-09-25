package utils

import (
	"encoding/json"
	"net/http"
)

func Respond(w http.ResponseWriter, r *http.Request, msg interface{}) {
	w.Header().Add("Content-Type", "application/json")
	_ = json.NewEncoder(w).Encode(msg)
}
