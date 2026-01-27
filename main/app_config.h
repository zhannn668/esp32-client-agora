#pragma once


//LLM Agent Service
#define TENAI_AGENT_URL       "http://<YOUR_SERVER_URL>:8080"

// LLM Agent Graph, you can select openai or gemini 
// #define CONFIG_GRAPH_OPENAI   /* openai, just only audio */
#define CONFIG_GRAPH_OPENAI     /* gemini, for video and audio, but not support chinese language */

/* greeting */
#define GREETING               "Can I help You?"
#define PROMPT                 ""

/* different settings for different agent graph */
#if defined(CONFIG_GRAPH_OPENAI)
#define GRAPH_NAME             "voice_assistant"

#define V2V_MODEL              "gpt-realtime"
#define LANGUAGE               "en-US"
#define VOICE                  "ash"
#elif defined(CONFIG_GRAPH_GEMINI)
#define GRAPH_NAME             "va_gemini_v2v"
#else
#error "not config graph for aiAgent"
#endif

// LLM Agent Task Name
#define AI_AGENT_NAME          "YOUR_AGENT_NAME"
// LLM Agent Channel Name
#define AI_AGENT_CHANNEL_NAME  "YOUR_CHANNEL_NAME"
// LLM User Id
#define AI_AGENT_USER_ID        12345 // user id, for device



/* function config */
/* audio codec */
#define CONFIG_USE_G711U_CODEC
/* video process */
// #define CONFIG_AUDIO_ONLY

#define AGORA_APP_ID "550749b706214846a1a2eef3612a8cd3"
